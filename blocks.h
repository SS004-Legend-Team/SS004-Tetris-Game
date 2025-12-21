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

// Hàm factory để tạo block mới dựa trên type
inline Blocks* createBlock(int type) {
    
}

#endif // BLOCKS_H

