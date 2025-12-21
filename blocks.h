#ifndef BLOCKS_H
#define BLOCKS_H

// Base class Blocks với tính đa hình
class Blocks {
protected:
    char shape[4][4];
    int rotationState;

public:
    Blocks() : rotationState(0) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                shape[i][j] = ' ';
    }
    
    virtual ~Blocks() {}
    
    // Lấy shape hiện tại
    char getCell(int i, int j) const {
        return shape[i][j];
    }
    
    // Virtual method để xoay - mỗi class con sẽ override
    virtual void rotate() = 0;
    
    // Kiểm tra có thể xoay không (dùng cho một số block đặc biệt)
    virtual bool canRotate() const {
        return true;
    }
};

// I-Block: có 2 trạng thái xoay
class IBlock : public Blocks {
public:
    IBlock() {
        shape[0][1] = 'I';
        shape[1][1] = 'I';
        shape[2][1] = 'I';
        shape[3][1] = 'I';
        rotationState = 0;
    }
    
    void rotate() override {
        // Xóa shape cũ
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                shape[i][j] = ' ';
        
        if (rotationState == 0) {
            // Chuyển từ dọc sang ngang
            shape[1][0] = 'I';
            shape[1][1] = 'I';
            shape[1][2] = 'I';
            shape[1][3] = 'I';
            rotationState = 1;
        } else {
            // Chuyển từ ngang sang dọc
            shape[0][1] = 'I';
            shape[1][1] = 'I';
            shape[2][1] = 'I';
            shape[3][1] = 'I';
            rotationState = 0;
        }
    }
};

// O-Block: không xoay
class OBlock : public Blocks {
public:
    OBlock() {
        shape[1][1] = 'O';
        shape[1][2] = 'O';
        shape[2][1] = 'O';
        shape[2][2] = 'O';
    }
    
    void rotate() override {
        // O-block không xoay, giữ nguyên
    }
    
    bool canRotate() const override {
        return false;
    }
};

// T-Block: có 4 trạng thái xoay
class TBlock : public Blocks {
public:
    TBlock() {
        shape[1][1] = 'T';
        shape[2][0] = 'T';
        shape[2][1] = 'T';
        shape[2][2] = 'T';
        rotationState = 0;
    }
    
    void rotate() override {
        char temp[4][4];
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                temp[i][j] = shape[3 - j][i];
        
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                shape[i][j] = temp[i][j];
        
        rotationState = (rotationState + 1) % 4;
    }
};

// S-Block: có 2 trạng thái xoay
class SBlock : public Blocks {
public:
    SBlock() {
        shape[1][1] = 'S';
        shape[1][2] = 'S';
        shape[2][0] = 'S';
        shape[2][1] = 'S';
        rotationState = 0;
    }
    
    void rotate() override {
        char temp[4][4];
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                temp[i][j] = shape[3 - j][i];
        
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                shape[i][j] = temp[i][j];
        
        rotationState = (rotationState + 1) % 2;
    }
};

// Hàm factory để tạo block mới dựa trên type
inline Blocks* createBlock(int type) {
    switch (type) {
        case 0: return new IBlock();
        case 1: return new OBlock();
        case 2: return new TBlock();
        case 3: return new SBlock();
       
        default: return new IBlock();
    }
}

#endif // BLOCKS_H

