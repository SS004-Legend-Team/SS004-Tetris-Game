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

// Hàm factory để tạo block mới dựa trên type
inline Blocks* createBlock(int type) {
    switch (type) {
        case 0: return new IBlock();
       
        default: return new IBlock();
    }
}

#endif // BLOCKS_H

