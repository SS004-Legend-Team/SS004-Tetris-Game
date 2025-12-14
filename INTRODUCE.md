# 🎮 SS004 - Tetris Game

## 📖 Giới thiệu

Chào mừng bạn đến với **Tetris** - trò chơi giải đố kinh điển đã chinh phục hàng triệu người chơi trên toàn thế giới! Tetris không chỉ là một trò chơi đơn giản, mà còn là một thử thách trí tuệ đầy thú vị, giúp bạn rèn luyện khả năng phản xạ, tư duy chiến lược và sự kiên nhẫn.

### 🎯 Tetris là gì?

Tetris được phát minh bởi nhà khoa học máy tính người Nga Alexey Pajitnov vào năm 1984. Tên gọi "Tetris" xuất phát từ tiếng Hy Lạp "tetra" (nghĩa là bốn) và "tennis" (môn thể thao yêu thích của Pajitnov). Trò chơi đã trở thành một trong những tựa game thành công nhất mọi thời đại, với hơn 500 triệu bản được bán ra trên toàn thế giới.

### ✨ Tại sao nên chơi Tetris?

- **Rèn luyện trí não**: Tetris giúp cải thiện khả năng tư duy không gian, phản xạ nhanh và kỹ năng giải quyết vấn đề
- **Giải trí lành mạnh**: Một cách tuyệt vời để thư giãn sau những giờ làm việc căng thẳng
- **Thử thách bản thân**: Cố gắng đạt điểm cao và phá vỡ kỷ lục của chính mình
- **Dễ học, khó giỏi**: Bất kỳ ai cũng có thể chơi, nhưng để trở thành cao thủ cần rất nhiều luyện tập

---

## 🎲 Cách chơi cơ bản

### Mục tiêu của trò chơi

Mục tiêu của Tetris rất đơn giản: **Sắp xếp các khối gạch (tetrominoes) rơi xuống để tạo thành các hàng ngang hoàn chỉnh**. Khi một hàng được lấp đầy hoàn toàn, nó sẽ biến mất và bạn sẽ nhận được điểm. Càng xóa được nhiều hàng cùng lúc, điểm số càng cao!

### 🧩 Các khối gạch (Tetrominoes)

Trong Tetris, có **7 loại khối gạch** khác nhau, mỗi khối được tạo thành từ 4 ô vuông:

1. **I-Block** (khối thẳng): Một đường thẳng dài 4 ô
   - Màu: Thường là màu xanh dương hoặc cyan
   - Đặc điểm: Khối dài nhất, rất hữu ích để xóa nhiều hàng cùng lúc

2. **O-Block** (khối vuông): Một hình vuông 2x2
   - Màu: Thường là màu vàng
   - Đặc điểm: Không thể xoay, nhưng rất ổn định

3. **T-Block** (khối chữ T): Hình chữ T
   - Màu: Thường là màu tím
   - Đặc điểm: Linh hoạt, có thể xoay theo 4 hướng

4. **S-Block** (khối chữ S): Hình chữ S
   - Màu: Thường là màu xanh lá
   - Đặc điểm: Có thể xoay, tạo thành hình chữ Z khi xoay

5. **Z-Block** (khối chữ Z): Hình chữ Z
   - Màu: Thường là màu đỏ
   - Đặc điểm: Đối xứng với S-Block

6. **J-Block** (khối chữ J): Hình chữ J
   - Màu: Thường là màu xanh dương đậm
   - Đặc điểm: Có thể xoay theo 4 hướng

7. **L-Block** (khối chữ L): Hình chữ L
   - Màu: Thường là màu cam
   - Đặc điểm: Đối xứng với J-Block

### 🎮 Điều khiển cơ bản

Trước khi bắt đầu chơi, hãy làm quen với các phím điều khiển:

- **⬅️ Di chuyển trái**: Nhấn phím mũi tên trái hoặc phím A để di chuyển khối sang trái
- **➡️ Di chuyển phải**: Nhấn phím mũi tên phải hoặc phím D để di chuyển khối sang phải
- **⬇️ Rơi nhanh**: Nhấn phím mũi tên xuống hoặc phím S để khối rơi nhanh hơn
- **🔄 Xoay khối**: Nhấn phím mũi tên lên hoặc phím W để xoay khối theo chiều kim đồng hồ
- **⏸️ Tạm dừng**: Nhấn phím P hoặc Space để tạm dừng trò chơi
- **⬇️⬇️ Thả rơi**: Nhấn phím Space để thả khối rơi thẳng xuống đáy ngay lập tức

> 💡 **Mẹo**: Hãy dành thời gian làm quen với các phím điều khiển trước khi bắt đầu chơi nghiêm túc!

---

## 🎯 Cơ chế chơi chi tiết

### 1. Khởi động trò chơi

Khi bắt đầu một ván chơi mới:
- Màn hình sẽ hiển thị một lưới trống (thường là 10 cột x 20 hàng)
- Khối gạch đầu tiên sẽ xuất hiện ở phía trên cùng
- Khối sẽ bắt đầu rơi xuống từ từ
- Ở góc màn hình, bạn sẽ thấy khối tiếp theo sẽ xuất hiện (Next Piece)

### 2. Di chuyển và xoay khối

Trong khi khối đang rơi, bạn có thể:
- **Di chuyển ngang**: Điều chỉnh vị trí khối để đặt vào vị trí mong muốn
- **Xoay khối**: Thay đổi hướng của khối để phù hợp với không gian còn lại
- **Rơi nhanh**: Tăng tốc độ rơi để tiết kiệm thời gian

### 3. Xóa hàng và ghi điểm

Khi một hàng ngang được lấp đầy hoàn toàn (không có khoảng trống nào), hàng đó sẽ:
- **Biến mất** khỏi màn hình
- **Các khối phía trên rơi xuống** để lấp đầy khoảng trống
- **Bạn nhận được điểm** tương ứng với số hàng đã xóa

### 4. Tăng tốc độ

Khi bạn xóa được nhiều hàng, trò chơi sẽ:
- **Tăng tốc độ rơi** của các khối
- **Tăng độ khó** để thử thách bạn
- **Tăng điểm số** cho mỗi hàng được xóa

### 5. Kết thúc trò chơi

Trò chơi sẽ kết thúc khi:
- **Các khối chồng lên đến đỉnh màn hình** và không còn chỗ cho khối mới
- Bạn không thể di chuyển hoặc xoay khối hiện tại
- Màn hình hiển thị "Game Over"

---

## 📊 Hệ thống điểm số

### Cách tính điểm

Điểm số được tính dựa trên số hàng bạn xóa trong một lần:

- **1 hàng (Single)**: 100 điểm × (Cấp độ + 1)
- **2 hàng (Double)**: 300 điểm × (Cấp độ + 1)
- **3 hàng (Triple)**: 500 điểm × (Cấp độ + 1)
- **4 hàng (Tetris)**: 800 điểm × (Cấp độ + 1)

### Cấp độ (Level)

- Bắt đầu từ **Cấp độ 1**
- Mỗi khi xóa được **10 hàng**, bạn sẽ lên một cấp
- Cấp độ càng cao, khối rơi càng nhanh và điểm số càng lớn

### Kỷ lục cá nhân

Hãy cố gắng phá vỡ kỷ lục của chính mình! Theo dõi:
- **Điểm số cao nhất** bạn đạt được
- **Cấp độ cao nhất** bạn đạt được
- **Số hàng đã xóa** trong một ván chơi

---

## 🎯 Chiến lược và mẹo chơi

### 1. Luôn để một cột trống

Một trong những chiến lược quan trọng nhất là **luôn để một hoặc hai cột ở giữa hoặc bên cạnh trống**. Điều này cho phép bạn sử dụng khối I (khối thẳng) để xóa nhiều hàng cùng lúc và đạt được Tetris (4 hàng).

### 2. Ưu tiên xóa hàng ở dưới

Hãy cố gắng **xóa các hàng ở phía dưới trước**. Điều này giúp:
- Giữ cho màn hình gọn gàng
- Tạo không gian cho các khối tiếp theo
- Tránh tình trạng các khối bị kẹt ở trên

### 3. Sử dụng "Next Piece" một cách thông minh

Luôn **quan sát khối tiếp theo** (Next Piece) để:
- Lên kế hoạch trước cho vị trí đặt khối hiện tại
- Chuẩn bị không gian cho khối tiếp theo
- Tránh tạo ra các khoảng trống khó lấp đầy

### 4. Xoay khối trước khi đặt

Thay vì di chuyển khối đến vị trí rồi mới xoay, hãy:
- **Xoay khối trước** khi nó rơi xuống quá thấp
- **Lên kế hoạch** hướng xoay từ sớm
- **Thực hành** các cách xoay khác nhau để quen tay

### 5. Không vội vàng

Mặc dù tốc độ tăng dần, nhưng đừng vội vàng:
- **Dành thời gian suy nghĩ** trước khi đặt khối
- **Kiểm tra** xem khối có thể xoay được không trước khi đặt
- **Giữ bình tĩnh** khi màn hình đầy lên

### 6. Tận dụng T-Spin

T-Spin là một kỹ thuật nâng cao:
- Sử dụng khối T để xoay vào một góc nhỏ
- Cho điểm số cao hơn và có thể xóa nhiều hàng
- Cần luyện tập nhiều để thành thạo

### 7. Quản lý không gian

- **Để lại các khoảng trống** có thể lấp đầy dễ dàng
- **Tránh tạo ra các cột quá cao** ở một bên
- **Cân bằng** chiều cao của các cột

---

## 🏆 Các thuật ngữ thường dùng

- **Tetris**: Xóa 4 hàng cùng lúc (điểm cao nhất)
- **T-Spin**: Kỹ thuật xoay khối T vào góc để tạo điểm cao
- **Combo**: Xóa nhiều hàng liên tiếp trong thời gian ngắn
- **Lock**: Khối được đặt cố định vào vị trí
- **Ghost Piece**: Hình bóng của khối hiển thị vị trí sẽ rơi xuống
- **Hold**: Giữ khối hiện tại để sử dụng sau
- **Next**: Khối tiếp theo sẽ xuất hiện

---

## 🎮 Chế độ chơi (nếu có)

### Chế độ Classic
- Chế độ chơi truyền thống
- Tốc độ tăng dần theo cấp độ
- Mục tiêu: Đạt điểm cao nhất có thể

### Chế độ Marathon
- Chơi đến khi Game Over
- Không giới hạn thời gian
- Thử thách độ bền của bạn

### Chế độ Sprint
- Xóa 40 hàng trong thời gian ngắn nhất
- Thử thách tốc độ và kỹ năng
- Hoàn hảo cho người chơi muốn luyện tập

---

## 💡 Câu hỏi thường gặp (FAQ)

### Q: Làm thế nào để đạt điểm cao?
**A**: Hãy cố gắng xóa 4 hàng cùng lúc (Tetris) thay vì xóa từng hàng một. Điều này cho điểm số cao hơn nhiều lần.

### Q: Tại sao khối rơi quá nhanh?
**A**: Tốc độ tăng dần theo cấp độ. Khi bạn xóa được nhiều hàng, bạn sẽ lên cấp và khối sẽ rơi nhanh hơn. Đây là một phần của thử thách!

### Q: Có thể xoay khối khi nó đã chạm đáy không?
**A**: Phụ thuộc vào phiên bản game. Trong hầu hết các phiên bản hiện đại, bạn có thể xoay khối ngay cả khi nó đã chạm đáy, miễn là có không gian.

### Q: Làm sao để cải thiện kỹ năng?
**A**: Thực hành thường xuyên! Bắt đầu với tốc độ chậm và từ từ tăng tốc. Học các kỹ thuật như T-Spin và quản lý không gian.

### Q: Có thể chơi lại sau khi Game Over không?
**A**: Có! Bạn có thể bắt đầu một ván chơi mới bất cứ lúc nào. Hãy cố gắng phá vỡ kỷ lục của chính mình!

---

## 🎉 Kết luận

Tetris là một trò chơi đơn giản nhưng đầy thử thách, phù hợp cho mọi lứa tuổi. Dù bạn là người mới bắt đầu hay đã là cao thủ, Tetris luôn có điều gì đó mới mẻ để khám phá.

### Những điều cần nhớ:

✅ **Thực hành thường xuyên** - Kỹ năng chỉ đến với luyện tập  
✅ **Giữ bình tĩnh** - Đừng hoảng sợ khi màn hình đầy lên  
✅ **Lên kế hoạch trước** - Quan sát khối tiếp theo và chuẩn bị  
✅ **Tận hưởng** - Đây là một trò chơi, hãy vui vẻ với nó!  

### Chúc bạn chơi vui vẻ! 🎮

Hãy bắt đầu ngay bây giờ và cố gắng phá vỡ kỷ lục của chính mình. Ai biết được, có thể bạn sẽ trở thành cao thủ Tetris tiếp theo!

---

**Phiên bản**: SS004  
**Ngày cập nhật**: 2024  
**Phát triển bởi**: SS004 Legend Team

---

*"Tetris không chỉ là một trò chơi, mà là một nghệ thuật của sự sắp xếp và chiến lược!"*
