# BÁO CÁO ĐỒ ÁN CUỐI KỲ
## Môn học: KỸ NĂNG NGHỀ NGHIỆP
### TETRIS GAME

**Nhóm thực hiện: 06**

- Nguyễn Hữu Lộc - MSSV: 25730038
- Nguyễn Thanh Lộc - MSSV: 25730039
- Trương Anh Khoa - MSSV: 25730035
- Nguyễn Đình Đức - MSSV: 25730017
- Hoàng Xuân Phong - MSSV: 25730052

**Giảng viên hướng dẫn:** ThS. Nguyễn Văn Toàn  
**Lớp:** SS004.F11.CN1.CNTT

TP. HỒ CHÍ MINH — Tháng 11 năm 2025

---

## A. LỜI MỞ ĐẦU

Để hoàn thành bài tập nhóm môn Kỹ năng nghề nghiệp với đề tài "Tetris Game", nhóm 06 đã nhận được sự hỗ trợ, quan tâm và động viên rất lớn từ Thầy Cô, gia đình và đồng nghiệp.

Trước hết, chúng em xin gửi lời tri ân sâu sắc đến Ban Giám hiệu Trường Đại học Công nghệ Thông tin và Trung tâm Phát triển Công nghệ Thông tin (CITD). Nhà trường đã xây dựng một chương trình đào tạo từ xa bài bản, linh hoạt, tạo điều kiện thuận lợi nhất cho những sinh viên vừa làm vừa học như chúng em.

Đặc biệt, nhóm xin cảm ơn Thạc sĩ Nguyễn Văn Toàn đã luôn tận tình hướng dẫn, giải đáp thắc mắc nhanh chóng và định hướng tư duy thực tế. Đây là nền tảng giúp nhóm hiểu rõ hơn về lộ trình hướng đến vị trí Tech Lead trong tương lai.

Cuối cùng, nhóm xin cảm ơn các thành viên nhóm 06 đã làm việc nghiêm túc, chủ động và trách nhiệm dù ai cũng có công việc và thời gian hạn chế.

Chúng em xin chân thành cảm ơn!

## B. TÓM TẮT

Đồ án này xây dựng một phiên bản hoàn chỉnh của tựa game xếp gạch (Tetris) kinh điển sử dụng ngôn ngữ lập trình C++. Dự án vận dụng các kỹ thuật lập trình hướng đối tượng (OOP) để thiết kế kiến trúc game, bao gồm các lớp quản lý khối gạch (Tetromino), bảng chơi (Board) và vòng lặp game (Game Loop). Về mặt thuật toán, đồ án tập trung giải quyết các bài toán về xử lý mảng hai chiều, kiểm tra va chạm, xóa hàng và cơ chế tính điểm. Sản phẩm cuối cùng không chỉ đảm bảo tính giải trí với giao diện trực quan, mượt mà mà còn thể hiện được kỹ năng quản lý bộ nhớ và tư duy logic thuật toán của người thực hiện.

## C. HỢP ĐỒNG NHÓM (GROUP CONTRACT)

### C.1. Thông tin chung

- **Tên nhóm:** Nhóm 06 - Team Legend
- **Mã lớp/Học phần:** SS004.F11.CN1.CNTT
- **Giảng viên hướng dẫn:** Nguyễn Văn Toàn
- **Thời gian thực hiện:** Từ ngày 01/12/2025 đến ngày 28/12/2025

### C.2. Mục đích thành lập

Nhóm được thành lập dựa trên sự tự nguyện và thống nhất của các thành viên với mục đích:

1. Hoàn thành xuất sắc đồ án cuối kỳ môn Kỹ Năng Nghề Nghiệp với đề tài Game Tetris.
2. Rèn luyện kỹ năng làm việc nhóm (teamwork), kỹ năng giải quyết vấn đề và quản lý xung đột.
3. Nâng cao trình độ lập trình C++, tư duy Hướng đối tượng (OOP) và sử dụng các công cụ quản lý mã nguồn.

### C.3. Công cụ và phương thức làm việc

Để đảm bảo tiến độ và chất lượng code, nhóm thống nhất sử dụng các công cụ sau:

- **Quản lý mã nguồn (Source Control):**
  - Sử dụng **GitHub** để lưu trữ code.
  - Quy tắc branch: Mỗi tính năng (feature) dev trên một branch riêng, chỉ merge vào `main` khi đã qua review.

- **Quản lý tác vụ (Task Management):**
  - Sử dụng **GitHub Projects** (dạng Kanban Board) để chia việc, theo dõi tiến độ (To do, In Progress, Done).

- **Giao tiếp (Communication):**
  - Sử dụng **Slack** làm kênh giao tiếp chính thức.
  - Các thông báo quan trọng, cập nhật daily, báo lỗi (bug report) sẽ được post lên channel tương ứng.
  - Họp tiến độ (Meeting): 1 lần/tuần (Offline hoặc Online qua Google Meet).

### C.4. Danh sách thành viên và Phân công vai trò

Nhóm bao gồm 5 thành viên với các vai trò cụ thể như sau:

| STT | Tên | MSSV | Nhiệm vụ trong đồ án Tetris |
|-----|-----|------|----------------------------|
| 1 | Nguyễn Thanh Lộc | 25730039 | Trưởng nhóm — điều phối chung, tổng hợp nội dung báo cáo, chuẩn hoá LaTeX, áp dụng tính đa hình cho lớp khối, hoàn thiện bản nộp cuối. |
| 2 | Nguyễn Hữu Lộc | 25730038 | Xây dựng chức năng xoá hàng khi đã hoàn thành và chịu trách nhiệm tổng hợp quá trình làm việc nhóm. |
| 3 | Trương Anh Khoa | 25730035 | Thiết kế giao diện trò chơi bố cục màn hình, trạng thái trò chơi và chịu trách nhiệm phần đánh giá hợp đồng nhóm. |
| 4 | Nguyễn Đình Đức | 25730017 | Phát triển cấu trúc chương trình và mô-đun điều khiển: vòng lặp game, tốc độ rơi, tăng dần độ khó. |
| 5 | Hoàng Xuân Phong | 25730052 | Thực hiện chức năng xoay khối khi đang rơi và chịu trách nhiệm tổng hợp các kỹ năng mà nhóm đã sử dụng để hoàn thành báo cáo. |

### C.5. Chỉ tiêu đánh giá (KPI)

Mỗi thành viên cam kết đạt được các chỉ tiêu sau:

1. **Tiến độ (Deadline):** Hoàn thành 100% task được giao đúng thời hạn trên GitHub Projects. Trễ deadline quá 2 lần không có lý do chính đáng sẽ bị trừ điểm đánh giá nội bộ.
2. **Chất lượng Code:** Code phải tuân thủ chuẩn coding style đã thống nhất, có comment rõ ràng. Không có lỗi biên dịch (compile error) khi đẩy lên nhánh chính.
3. **Thái độ:** Tham gia đầy đủ các buổi họp nhóm (vắng mặt phải báo trước). Phản hồi tin nhắn trên Slack trong vòng 4 tiếng (trong giờ làm việc).
4. **Mục tiêu chung:** Đồ án đạt điểm tổng kết từ 8.0 trở lên. Game chạy mượt mà, không có lỗi Crash (Fatal Error).

### C.6. Quyết định thành lập nhóm

Căn cứ vào yêu cầu của môn học và sự thống nhất của các thành viên, chúng tôi quyết định thành lập nhóm để thực hiện đồ án này. Hợp đồng này có hiệu lực kể từ ngày ký cho đến khi đồ án được bảo vệ thành công và có điểm số cuối cùng.

### C.7. Cam kết

Chúng tôi, những thành viên có tên dưới đây, đã đọc, hiểu và đồng ý với tất cả các điều khoản trong bản hợp đồng này. Chúng tôi cam kết thực hiện nghiêm túc nghĩa vụ của mình để đạt được mục tiêu chung của nhóm.

| STT | Tên thành viên | MSSV | Chữ ký |
|-----|----------------|------|--------|
| 1 | Nguyễn Thanh Lộc | 25730039 | [Chữ ký] |
| 2 | Nguyễn Hữu Lộc | 25730038 | [Chữ ký] |
| 3 | Trương Anh Khoa | 25730035 | [Chữ ký] |
| 4 | Nguyễn Đình Đức | 25730017 | [Chữ ký] |
| 5 | Hoàng Xuân Phong | 25730052 | [Chữ ký] |

## D. GITHUB/SLACK/OVERLEAF MÀ NHÓM ĐÃ DÙNG

Để đảm bảo tính minh bạch và giảng viên có thể theo dõi quá trình làm việc, nhóm cung cấp các đường dẫn truy cập vào tài nguyên làm việc như sau:

### 1. GitHub (Quản lý Mã nguồn & Tiến độ)

Nhóm sử dụng GitHub để lưu trữ Code và tính năng GitHub Projects để chia task (Kanban).

- **Đường dẫn Repository:**  
  [https://github.com/SS004-Legend-Team/SS004-Tetris-Game](https://github.com/SS004-Legend-Team/SS004-Tetris-Game)

- **GitHub Project Board (Quản lý Task):**  
  [https://github.com/orgs/SS004-Legend-Team/projects/2](https://github.com/orgs/SS004-Legend-Team/projects/2)

### 2. Slack (Giao tiếp & Họp nhóm)

Slack là nơi trao đổi nhanh, gửi file

- **Slack Workspace URL:**  
  [https://ss004f11cn1.slack.com/archives/C09RWCQE8DU](https://ss004f11cn1.slack.com/archives/C09RWCQE8DU)

### 3. Overleaf (Soạn thảo Báo cáo)

Toàn bộ tài liệu báo cáo, slide thuyết trình và hợp đồng nhóm này đều được soạn thảo cộng tác trên Overleaf.

- **Link dự án (View Only):**  
  [https://www.overleaf.com/project/69350ba6428d6b170bf29c1e](https://www.overleaf.com/project/69350ba6428d6b170bf29c1e)

## E. PHẦN GIỚI THIỆU VÀ HƯỚNG DẪN CHƠI GAME

Chào mừng bạn đến với **Tetris** - trò chơi giải đố kinh điển đã chinh phục hàng triệu người chơi trên toàn thế giới! Tetris không chỉ là một trò chơi đơn giản, mà còn là một thử thách trí tuệ đầy thú vị, giúp bạn rèn luyện khả năng phản xạ, tư duy chiến lược và sự kiên nhẫn.

### E.1. Tetris là gì?

Tetris được phát minh bởi nhà khoa học máy tính người Nga Alexey Pajitnov vào năm 1984. Tên gọi "Tetris" xuất phát từ tiếng Hy Lạp "tetra" (nghĩa là bốn) và "tennis" (môn thể thao yêu thích của Pajitnov). Trò chơi đã trở thành một trong những tựa game thành công nhất mọi thời đại, với hơn 500 triệu bản được bán ra trên toàn thế giới.

### E.2. Tại sao nên chơi Tetris?

- **Rèn luyện trí não:** Tetris giúp cải thiện khả năng tư duy không gian, phản xạ nhanh và kỹ năng giải quyết vấn đề.
- **Giải trí lành mạnh:** Một cách tuyệt vời để thư giãn sau những giờ làm việc căng thẳng.
- **Thử thách bản thân:** Cố gắng đạt điểm cao và phá vỡ kỷ lục của chính mình.
- **Dễ học, khó giỏi:** Bất kỳ ai cũng có thể chơi, nhưng để trở thành cao thủ cần rất nhiều luyện tập.

### E.3. Cách chơi cơ bản

#### E.3.1. Mục tiêu của trò chơi

Mục tiêu của Tetris rất đơn giản: **Sắp xếp các khối gạch (tetrominoes) rơi xuống để tạo thành các hàng ngang hoàn chỉnh**. Khi một hàng được lấp đầy hoàn toàn, nó sẽ biến mất và bạn sẽ nhận được điểm. Càng xóa được nhiều hàng cùng lúc, điểm số càng cao!

#### E.3.2. Các khối gạch (Tetrominoes)

Trong Tetris, có **7 loại khối gạch** khác nhau, mỗi khối được tạo thành từ 4 ô vuông:

1. **I-Block (Khối thẳng):** Một đường thẳng dài 4 ô.
   - Đặc điểm: Khối dài nhất, rất hữu ích để xóa nhiều hàng cùng lúc.

2. **O-Block (Khối vuông):** Một hình vuông 2×2.
   - Đặc điểm: Không thể xoay, nhưng rất ổn định.

3. **T-Block (Khối chữ T):** Hình chữ T.
   - Đặc điểm: Linh hoạt, có thể xoay theo 4 hướng.

4. **S-Block (Khối chữ S):** Hình chữ S.
   - Đặc điểm: Có thể xoay, tạo thành hình chữ Z khi xoay.

5. **Z-Block (Khối chữ Z):** Hình chữ Z.
   - Đặc điểm: Đối xứng với S-Block.

6. **J-Block (Khối chữ J):** Hình chữ J.
   - Đặc điểm: Có thể xoay theo 4 hướng.

7. **L-Block (Khối chữ L):** Hình chữ L.
   - Đặc điểm: Đối xứng với J-Block.

#### E.3.3. Điều khiển cơ bản

Trước khi bắt đầu chơi, hãy làm quen với các phím điều khiển:

- **← Di chuyển trái:** Nhấn phím mũi tên trái hoặc phím A để di chuyển khối sang trái.
- **→ Di chuyển phải:** Nhấn phím mũi tên phải hoặc phím D để di chuyển khối sang phải.
- **↓ Rơi nhanh:** Nhấn phím mũi tên xuống hoặc phím S để khối rơi nhanh hơn.
- **↻ Xoay khối:** Nhấn phím mũi tên lên hoặc phím W để xoay khối theo chiều kim đồng hồ.
- **⏸ Tạm dừng:** Nhấn phím P hoặc Space để tạm dừng trò chơi.
- **↓↓ Thả rơi:** Nhấn phím Space để thả khối rơi thẳng xuống đáy ngay lập tức.

> **💡 Mẹo:** Hãy dành thời gian làm quen với các phím điều khiển trước khi bắt đầu chơi nghiêm túc!

### E.4. Cơ chế chơi chi tiết

1. **Khởi động trò chơi:**  
   Khi bắt đầu một ván chơi mới, màn hình sẽ hiển thị một lưới trống (thường là 10 cột x 20 hàng). Khối gạch đầu tiên xuất hiện ở trên cùng và bắt đầu rơi xuống. Bạn có thể thấy khối tiếp theo tại ô "Next Piece".

2. **Di chuyển và xoay khối:**  
   Trong khi khối đang rơi, bạn cần điều chỉnh vị trí ngang và xoay hướng để phù hợp với không gian bên dưới. Bạn cũng có thể tăng tốc độ rơi để tiết kiệm thời gian.

3. **Xóa hàng và ghi điểm:**  
   Khi một hàng ngang được lấp đầy hoàn toàn, hàng đó sẽ biến mất. Các khối phía trên sẽ rơi xuống lấp đầy khoảng trống và bạn nhận được điểm.

4. **Tăng tốc độ:**  
   Khi xóa được nhiều hàng, trò chơi sẽ tăng tốc độ rơi của các khối và tăng độ khó, đồng thời điểm thưởng cũng cao hơn.

5. **Kết thúc trò chơi:**  
   Trò chơi kết thúc (Game Over) khi các khối chồng lên đến đỉnh màn hình và không còn chỗ cho khối mới xuất hiện.

### E.5. Hệ thống điểm số

#### Cách tính điểm

Điểm số được tính dựa trên số hàng bạn xóa trong một lần rơi:

- **1 hàng (Single):** 100 × (Cấp độ + 1)
- **2 hàng (Double):** 300 × (Cấp độ + 1)
- **3 hàng (Triple):** 500 × (Cấp độ + 1)
- **4 hàng (Tetris):** 800 × (Cấp độ + 1)

#### Cấp độ và Kỷ lục

Bạn bắt đầu từ **Cấp độ 1**. Mỗi khi xóa được **10 hàng**, bạn sẽ lên một cấp. Hãy cố gắng phá vỡ kỷ lục của chính mình về Điểm số cao nhất, Cấp độ cao nhất và Số hàng đã xóa.

### E.6. Chiến lược và mẹo chơi

1. **Luôn để một cột trống:** Giữ một cột dọc trống (thường ở sát biên) để chờ khối I (thẳng dài) nhằm ghi điểm Tetris (xóa 4 hàng cùng lúc).
2. **Ưu tiên xóa hàng ở dưới:** Giúp màn hình gọn gàng và tránh bị dồn khối lên quá cao.
3. **Sử dụng "Next Piece":** Luôn liếc nhìn khối tiếp theo để lên kế hoạch đặt khối hiện tại sao cho phù hợp.
4. **Xoay khối trước khi đặt:** Đừng đợi khối rơi xuống đáy mới xoay, hãy xoay từ sớm để tránh bị kẹt.
5. **Tận dụng T-Spin:** Đây là kỹ thuật nâng cao, xoay khối T vào các khe hẹp để ghi điểm thưởng lớn.
6. **Quản lý không gian:** Cố gắng giữ bề mặt các khối bằng phẳng, tránh tạo ra các "tháp" quá cao lởm chởm.

### E.7. Các thuật ngữ thường dùng

- **Tetris:** Hành động xóa 4 hàng cùng lúc (điểm cao nhất).
- **T-Spin:** Kỹ thuật xoay khối T vào góc hẹp.
- **Combo:** Xóa nhiều hàng liên tiếp trong chuỗi các nước đi.
- **Ghost Piece:** Hình bóng mờ của khối hiển thị vị trí nó sẽ rơi xuống.
- **Hold:** Chức năng giữ khối hiện tại lại để dùng sau.

### E.8. Câu hỏi thường gặp (FAQ)

**Q: Làm thế nào để đạt điểm cao?**  
A: Hãy cố gắng tích các hàng và chờ khối I để xóa 4 hàng cùng lúc (Tetris). Điểm số sẽ cao hơn nhiều so với xóa lẻ tẻ.

**Q: Tại sao khối rơi quá nhanh?**  
A: Tốc độ tăng dần theo cấp độ. Đây là cơ chế cốt lõi để tạo độ khó cho game.

**Q: Có thể xoay khối khi nó đã chạm đáy không?**  
A: Tùy phiên bản. Hầu hết các bản hiện đại (như bản SS004 này) cho phép "Lock Delay" - một khoảng thời gian ngắn để bạn xoay hoặc trượt khối trước khi nó bị khóa cứng.

**Q: Làm sao để cải thiện kỹ năng?**  
A: Thực hành thường xuyên! Tập trung vào việc xếp phẳng bề mặt và làm quen với tính năng "Hold".

### E.9. Kết luận

Tetris là một trò chơi đơn giản nhưng đầy thử thách, phù hợp cho mọi lứa tuổi. Dù bạn là người mới bắt đầu hay đã là cao thủ, Tetris luôn có điều gì đó mới mẻ để khám phá.

- ✅ **Thực hành thường xuyên** - Kỹ năng chỉ đến với luyện tập.
- ✅ **Giữ bình tĩnh** - Đừng hoảng sợ khi màn hình đầy lên.
- ✅ **Lên kế hoạch trước** - Quan sát khối tiếp theo.
- ✅ **Tận hưởng** - Hãy vui vẻ với nó!

> *"Tetris không chỉ là một trò chơi, mà là một nghệ thuật của sự sắp xếp và chiến lược!"*

## H. TÀI LIỆU KỸ THUẬT CỦA TRÒ CHƠI

Phần này trình bày chi tiết về kiến trúc, cấu trúc dữ liệu, các module chính và thuật toán của trò chơi Tetris được xây dựng bằng C++ với phương pháp lập trình hướng đối tượng (OOP) và tính đa hình (Polymorphism).

### H.1. Tổng quan

#### H.1.1. Mô tả

Tetris là trò chơi puzzle cổ điển, người chơi điều khiển các khối hình (tetromino) rơi xuống và sắp xếp chúng để tạo thành các dòng hoàn chỉnh. Khi một dòng được lấp đầy, nó sẽ bị xóa và người chơi được điểm. Tốc độ rơi tăng dần theo level.

#### H.1.2. Công nghệ sử dụng

- **Ngôn ngữ:** C++
- **Paradigm:** Hướng đối tượng (OOP) với tính đa hình (Polymorphism)
- **Platform:**
  - Windows: `main.cpp` (sử dụng `conio.h`, `windows.h`)
  - macOS/Linux: `main-macos.cpp` (sử dụng `termios.h`, `unistd.h`)

#### H.1.3. Cấu trúc file

```
SS004-Tetris-Game/
├── blocks.h          # Định nghĩa các class Blocks và derived classes
├── main.cpp          # Code chính cho Windows
├── main-macos.cpp    # Code chính cho macOS/Linux
└── TECHNICAL_DOCUMENTATION.md  # Tài liệu markdown
```

### H.2. Kiến trúc hệ thống

#### H.2.1. Kiến trúc tổng quan

Hệ thống được chia thành các module chính:

- **Input Handler:** Xử lý input từ bàn phím
- **Game Logic Controller:** Điều khiển logic game
- **Render System:** Hiển thị game lên màn hình

Các module này tương tác với:
- **Blocks.h (OOP):** Quản lý các khối gạch
- **Game Board (2D Array):** Lưu trữ trạng thái bàn chơi
- **Console Screen:** Hiển thị output

#### H.2.2. Mô hình hướng đối tượng

Hệ thống sử dụng **Design Pattern: Factory Pattern** và **Polymorphism**:

- **Base Class:** `Blocks` (abstract class)
- **Derived Classes:** `IBlock`, `OBlock`, `TBlock`, `SBlock`, `ZBlock`, `JBlock`, `LBlock`
- **Factory Function:** `createBlock(int type)`

### H.3. Cấu trúc dữ liệu

#### H.3.1. Game Board

```cpp
char board[H][W];  // H = 20, W = 15
```

- Mảng 2 chiều biểu diễn trạng thái bàn chơi
- `' '` = ô trống
- `'I'`, `'O'`, `'T'`, `'S'`, `'Z'`, `'J'`, `'L'` = các loại block

#### H.3.2. Block Shape

```cpp
char shape[4][4];  // Mỗi block được biểu diễn trong ma trận 4x4
```

- Mỗi block chiếm tối đa 4x4 ô
- Chỉ một phần của ma trận chứa block thực tế

#### H.3.3. Game State Variables

```cpp
int level = 1;              // Level hiện tại
int totalLines = 0;          // Tổng số dòng đã xóa
int fallDelay = BASE_DELAY;  // Thời gian delay giữa các lần rơi (ms)
int x, y;                    // Vị trí block hiện tại trên board
Blocks* currentBlock;         // Con trỏ đến block đang rơi
```

#### H.3.4. Constants

```cpp
#define H 20                  // Chiều cao board
#define W 15                  // Chiều rộng board
#define MIN_DELAY 100         // Delay tối thiểu (ms)
#define BASE_DELAY 1000       // Delay cơ bản (ms)
#define SPEED_STEP 40         // Bước tăng tốc mỗi level
#define LINES_PER_LEVEL 5     // Số dòng cần xóa để lên level
```

### H.4. Các module chính

#### H.4.1. Module Blocks (blocks.h)

**Class Blocks (Base Class):**

```cpp
class Blocks {
protected:
    char shape[4][4];
    int rotationState;
public:
    virtual ~Blocks();
    char getCell(int i, int j) const;
    virtual void rotate() = 0;  // Pure virtual - đa hình
    virtual bool canRotate() const;
};
```

**Trách nhiệm:**

- Định nghĩa interface chung cho tất cả các block
- Cung cấp phương thức truy cập shape
- Định nghĩa virtual method `rotate()` để các class con override

**Derived Classes:**

| Class | Số trạng thái xoay | Mô tả |
|-------|-------------------|-------|
| `IBlock` | 2 | Block thẳng (dọc/ngang) |
| `OBlock` | 0 | Block vuông (không xoay) |
| `TBlock` | 4 | Block hình chữ T |
| `SBlock` | 2 | Block hình chữ S |
| `ZBlock` | 2 | Block hình chữ Z |
| `JBlock` | 4 | Block hình chữ J |
| `LBlock` | 4 | Block hình chữ L |

**Ví dụ cấu trúc IBlock:**

```
Trạng thái 0 (dọc):      Trạng thái 1 (ngang):
    [ ]                      [ ][ ][ ][ ]
    [I]                      [I][I][I][I]
    [I]                      [ ]
    [I]                      [ ]
    [I]
```

#### H.4.2. Module Game Logic

**Di chuyển và va chạm:**

```cpp
bool canMove(int dx, int dy)
```

- Kiểm tra block có thể di chuyển theo hướng `(dx, dy)` không
- Kiểm tra biên và va chạm với các block đã đặt

**Xoay block:**

```cpp
bool canRotateBlock()
void rotateBlock()
```

- `canRotateBlock()`: Kiểm tra vị trí sau khi xoay có hợp lệ không
- `rotateBlock()`: Sử dụng **polymorphism** - gọi `currentBlock->rotate()`
- Mỗi loại block tự xử lý logic xoay riêng

**Xóa dòng:**

```cpp
int removeLine()
```

- Quét từ dưới lên để tìm dòng đầy
- Xóa dòng và dịch chuyển các dòng phía trên xuống
- Trả về số dòng đã xóa

**Cập nhật tốc độ:**

```cpp
void updateSpeed(int linesRemoved)
```

- Cộng dồn `totalLines`
- Tính `level = totalLines / LINES_PER_LEVEL + 1`
- Giảm `fallDelay = BASE_DELAY - (level - 1) * SPEED_STEP`
- Giới hạn `fallDelay >= MIN_DELAY`

#### H.4.3. Module Rendering

**Vẽ board:**

```cpp
void draw()
```

- Xóa màn hình (`system("cls")` hoặc `system("clear")`)
- Vẽ border và board
- Hiển thị thông tin: Level, Lines, Delay

**Quản lý block trên board:**

```cpp
void block2Board()    // Vẽ block lên board
void boardDelBlock()  // Xóa block khỏi board (để di chuyển)
```

#### H.4.4. Module Input Handling

**Windows (main.cpp):**

- Sử dụng `conio.h`: `kbhit()`, `getch()`
- `Sleep()` từ `windows.h`

**macOS/Linux (main-macos.cpp):**

- Tự implement `kbhit()` và `getch()` bằng `termios.h`
- Sử dụng `this_thread::sleep_for()` từ C++11

**Bảng điều khiển:**

| Phím | Chức năng |
|------|-----------|
| `a` | Di chuyển trái |
| `d` | Di chuyển phải |
| `x` | Rơi nhanh |
| `w` hoặc `r` | Xoay block |
| `q` | Thoát game |

### H.5. Sơ đồ khối (Flowchart)

#### H.5.1. Sơ đồ tổng quan - Game Loop

```
START
  ↓
Initialize (Random seed, Create 1st block, Init board)
  ↓
GAME LOOP
  ↓
Remove block from board
  ↓
Check keyboard?
  ├─ Yes → Process Input (Move/Rotate/Quit)
  └─ No  ↓
Can move down?
  ├─ Yes → Move down
  └─ No  → Block landed (Lock block, Check lines, Remove full lines, Update speed, New block)
  ↓
Draw block to board
  ↓
Render screen
  ↓
Sleep (fallDelay)
  ↓
[Quay lại GAME LOOP]
```

#### H.5.2. Sơ đồ xử lý xoay block (Polymorphism)

```
User presses 'w' or 'r'
  ↓
rotateBlock()
  ↓
currentBlock exists? canRotate()?
  ├─ No → Return
  └─ Yes ↓
canRotateBlock() - Check if rotation valid
  ↓
Valid?
  ├─ No → Return
  └─ Yes ↓
POLYMORPHISM: currentBlock->rotate()
  (Each block type has its own rotation logic)
```

#### H.5.3. Sơ đồ xóa dòng

```
removeLine()
  ↓
Loop from bottom to top (i = H-2 to 1)
  ↓
Line i is full?
  ├─ Yes → removed++
  │        Shift all lines above down by 1
  │        Clear top line
  │        i++ (recheck same line)
  │        ↓
  │        [Quay lại kiểm tra Line i]
  └─ No  ↓
Return removed (total lines)
```

### H.6. Sơ đồ Class (Class Diagram)

```
                    Blocks (Abstract Class)
                    - shape[4][4]
                    - rotationState
                    + getCell()
                    + rotate() = 0
                    + canRotate()
                           |
        ┌──────────────────┼──────────────────┐
        |                  |                   |
    IBlock            OBlock              TBlock
    + rotate()        + rotate()          + rotate()
    (2 states)        (no rot)            (4 states)
        |                  |                   |
        └──────────────────┼──────────────────┘
                           |
        ┌──────────────────┼──────────────────┐
        |                  |                   |
    SBlock            ZBlock              JBlock
    + rotate()        + rotate()          + rotate()
    (2 states)        (2 states)          (4 states)
        |                  |                   |
        └──────────────────┼──────────────────┘
                           |
                      LBlock
                      + rotate()
                      (4 states)

                    createBlock()
                    (Factory Function)
                    + createBlock(type)
                    Returns Blocks*
```

### H.7. Thuật toán chính

#### H.7.1. Thuật toán xoay block (Rotation Algorithm)

**Cho các block xoay 90° (T, S, Z, J, L):**

```
new[i][j] = old[3-j][i]
```

Ví dụ với ma trận 4x4:

```
[0][0] [0][1] [0][2] [0][3]      [3][0] [2][0] [1][0] [0][0]
[1][0] [1][1] [1][2] [1][3]  →   [3][1] [2][1] [1][1] [0][1]
[2][0] [2][1] [2][2] [2][3]      [3][2] [2][2] [1][2] [0][2]
[3][0] [3][1] [3][2] [3][3]      [3][3] [2][3] [1][3] [0][3]
```

**Cho IBlock (đặc biệt):**

- Chỉ có 2 trạng thái: dọc ↔ ngang
- Logic riêng: xóa và vẽ lại shape

#### H.7.2. Thuật toán kiểm tra va chạm

```cpp
bool canMove(int dx, int dy) {
    for mỗi ô (i, j) trong shape[4][4]:
        if shape[i][j] != ' ':
            xt = x + j + dx
            yt = y + i + dy
            if (xt < 1 || xt >= W-1 || yt >= H-1):
                return false  // Vượt biên
            if (board[yt][xt] != ' '):
                return false  // Va chạm với block khác
    return true
}
```

#### H.7.3. Thuật toán xóa dòng

```cpp
int removeLine() {
    removed = 0
    for i từ H-2 xuống 1:
        if dòng i đầy:
            removed++
            // Dịch chuyển tất cả dòng phía trên xuống
            for r từ i xuống 2:
                board[r] = board[r-1]
            // Xóa dòng trên cùng
            board[1] = ' ' (toàn bộ)
            i++  // Kiểm tra lại dòng i (vì đã dịch xuống)
    return removed
}
```

#### H.7.4. Thuật toán cập nhật tốc độ

```cpp
void updateSpeed(int linesRemoved) {
    totalLines += linesRemoved
    level = totalLines / LINES_PER_LEVEL + 1
    fallDelay = BASE_DELAY - (level - 1) * SPEED_STEP
    if (fallDelay < MIN_DELAY):
        fallDelay = MIN_DELAY
}
```

**Ví dụ:**

- Level 1: `fallDelay = 1000ms`
- Level 2: `fallDelay = 960ms` (sau 5 dòng)
- Level 3: `fallDelay = 920ms` (sau 10 dòng)
- ...
- Level 24: `fallDelay = 100ms` (tối đa)

### H.8. Tính năng đặc biệt

#### H.8.1. Polymorphism (Đa hình)

**Ưu điểm:**

- Mỗi loại block tự quản lý logic xoay riêng
- Dễ mở rộng: thêm block mới chỉ cần tạo class mới
- Code sạch, dễ bảo trì

**Ví dụ sử dụng:**

```cpp
Blocks* block = createBlock(2);  // Tạo TBlock
block->rotate();  // Gọi rotate() của TBlock, không phải Blocks
```

#### H.8.2. Factory Pattern

Hàm `createBlock()` đóng vai trò Factory:

- Tạo object dựa trên type
- Ẩn chi tiết khởi tạo
- Dễ thêm block mới

#### H.8.3. Cross-platform Support

- **Windows:** `main.cpp` với `conio.h`
- **macOS/Linux:** `main-macos.cpp` với `termios.h`
- Cùng logic game, chỉ khác input/output

### H.9. Điểm mạnh và hạn chế

#### H.9.1. Điểm mạnh

- ✅ Sử dụng OOP với polymorphism
- ✅ Code được tổ chức rõ ràng (tách file)
- ✅ Hỗ trợ đa nền tảng
- ✅ Dễ mở rộng (thêm block mới)
- ✅ Logic game hoàn chỉnh (di chuyển, xoay, xóa dòng, tăng tốc)

#### H.9.2. Hạn chế và cải tiến có thể

- ❌ Chưa có hệ thống điểm số
- ❌ Chưa có preview block tiếp theo
- ❌ Chưa có hold block
- ❌ Chưa có game over detection
- ❌ Chưa có high score
- ❌ Chưa có âm thanh

### H.10. Hướng dẫn biên dịch và chạy

#### H.10.1. Windows

```bash
g++ main.cpp -o tetris.exe
./tetris.exe
```

#### H.10.2. macOS/Linux

```bash
g++ main-macos.cpp -o tetris -std=c++11
./tetris
```

#### H.10.3. Yêu cầu

- Compiler hỗ trợ C++11 trở lên
- Windows: cần `conio.h` và `windows.h`
- macOS/Linux: cần `termios.h` và `unistd.h`

> **💡 Kết luận:** Trò chơi Tetris này được xây dựng với kiến trúc OOP sử dụng polymorphism, Design Pattern Factory Pattern, cấu trúc code rõ ràng dễ bảo trì và hỗ trợ đa nền tảng. Code minh họa tốt các khái niệm Inheritance, Polymorphism, Virtual functions, Factory Pattern và Memory management.

## I. MÔ TẢ QUÁ TRÌNH LÀM VIỆC NHÓM

### I.1. Giai đoạn khởi động và phân công ban đầu

Ở giai đoạn đầu, nhóm thống nhất yêu cầu của đề tài và xác định các chức năng chính của trò chơi Tetris Game. Nhóm trưởng tiến hành phân chia công việc ban đầu cho các thành viên và tạo các nhiệm vụ trên GitHub Projects.

Mỗi thành viên được giao một phần chức năng cụ thể và thực hiện trên nhánh riêng nhằm tránh xung đột mã nguồn.

Ngay từ đầu dự án, nhóm trưởng tiến hành phân chia công việc cho từng thành viên dựa trên yêu cầu của đề tài. Các nhiệm vụ được tạo và quản lý trên GitHub Projects dưới dạng các thẻ công việc (Issue/Task), trong đó mỗi task đều có mô tả rõ ràng và người phụ trách cụ thể.

Việc phân công giúp các thành viên chủ động trong công việc và tránh chồng chéo chức năng trong quá trình lập trình.

### I.2. Quy trình làm việc với GitHub

Nhóm sử dụng GitHub để quản lý mã nguồn và phối hợp làm việc theo các bước sau:

1. Các thành viên nhận task được phân công trên GitHub Projects.
2. Mỗi thành viên tạo nhánh riêng (branch) để thực hiện chức năng được giao.
3. Sau khi hoàn thành, thành viên tạo Pull Request để gửi mã nguồn lên nhánh chính.
4. Nhóm trưởng và các thành viên khác tiến hành review mã nguồn.
5. Sau khi sửa lỗi và hoàn thiện, mã nguồn được merge vào nhánh chính của dự án.

Quy trình này giúp hạn chế lỗi và đảm bảo tính ổn định của chương trình.

### I.3. Giai đoạn phát triển và các khó khăn gặp phải

Trong quá trình lập trình, nhóm gặp một số khó khăn như:

- Lỗi biên dịch do cách tổ chức hàm và biến toàn cục chưa hợp lý.
- Một số chức năng có logic phức tạp, đặc biệt là xử lý xóa dòng trong trò chơi Tetris.
- Xung đột mã nguồn khi nhiều thành viên cùng chỉnh sửa các phần liên quan.

Những khó khăn này ảnh hưởng đến tiến độ và yêu cầu nhóm phải điều chỉnh lại cách làm việc.

### I.4. Theo dõi tiến độ công việc

Tiến độ dự án được theo dõi thông qua bảng Kanban trên GitHub Projects với các trạng thái:

- **Backlog:** Các công việc chưa bắt đầu
- **In Progress:** Các công việc đang được thực hiện
- **In Review:** Các công việc đang được kiểm tra
- **Done:** Các công việc đã hoàn thành

Việc sử dụng Kanban Board giúp nhóm dễ dàng kiểm soát tiến độ và nắm được tình trạng của từng nhiệm vụ.

### I.5. Phối hợp và xử lý lỗi

Trong quá trình phát triển, các thành viên thường xuyên trao đổi với nhau thông qua kênh chat để thảo luận về lỗi, logic chương trình và cách cải tiến chức năng. Khi phát hiện lỗi trong quá trình review, nhóm sẽ ghi chú cụ thể và yêu cầu chỉnh sửa trước khi merge code.

Việc review chéo giúp nâng cao chất lượng mã nguồn và giúp các thành viên học hỏi lẫn nhau. Khi phát sinh lỗi và khó khăn, nhóm tiến hành rà soát lại nhiệm vụ của từng thành viên. Một số công việc được điều chỉnh và phân chia lại để phù hợp hơn với khả năng của từng người.

Các thành viên trao đổi trực tiếp và thông qua công cụ GitHub để:

- Review mã nguồn của nhau.
- Ghi chú lỗi và đề xuất hướng sửa thông qua Pull Request.
- Chỉnh sửa lại logic chương trình dựa trên góp ý chung của nhóm.

Việc phân chia lại công việc giúp nhóm xử lý được các lỗi tồn đọng và cải thiện chất lượng chương trình.

### I.6. Giai đoạn hoàn thiện và tích hợp

Sau khi các chức năng chính được sửa lỗi và hoàn thiện, nhóm tiến hành tích hợp toàn bộ chương trình trên nhánh chính. Các thành viên tiếp tục kiểm thử tổng thể, điều chỉnh lại giao diện và tốc độ trò chơi để đảm bảo chương trình hoạt động ổn định.

Những lỗi phát sinh ở giai đoạn cuối được xử lý nhanh chóng thông qua việc trao đổi và hỗ trợ lẫn nhau.

### I.7. Đánh giá quá trình làm việc nhóm

Thông qua các giai đoạn thực hiện đồ án, nhóm rút ra được nhiều kinh nghiệm về làm việc nhóm, đặc biệt là kỹ năng phân công công việc, phối hợp sửa lỗi và sử dụng GitHub trong quản lý dự án. Việc chủ động điều chỉnh và phân chia lại công việc giúp nhóm hoàn thành đồ án đúng hạn và đạt được mục tiêu đề ra.

## J. CÁC KỸ NĂNG MÀ NHÓM ĐÃ ÁP DỤNG TRONG ĐỒ ÁN

## K. ĐÁNH GIÁ VIỆC THỰC HIỆN HỢP ĐỒNG NHÓM

Căn cứ vào hợp đồng nhóm và bảng phân công nhiệm vụ đã thống nhất, trong suốt quá trình thực hiện đồ án Tetris, các thành viên trong nhóm đã thực hiện đúng và đầy đủ vai trò, trách nhiệm được giao. Nhóm làm việc với tinh thần nghiêm túc, hợp tác và có sự phối hợp chặt chẽ giữa các thành viên nhằm đảm bảo tiến độ và chất lượng của sản phẩm cuối cùng.

Thành viên **Nguyễn Thanh Lộc** (MSSV: 25730039), với vai trò **trưởng nhóm**, đã thực hiện tốt nhiệm vụ điều phối chung, theo dõi tiến độ của các thành viên, tổng hợp nội dung báo cáo và chuẩn hóa định dạng LaTeX. Đặc biệt, thành viên đã áp dụng thành công tính đa hình (polymorphism) cho lớp khối, chuyển đổi từ cấu trúc mảng sang hệ thống class với virtual methods, góp phần nâng cao chất lượng code và thể hiện rõ tư duy lập trình hướng đối tượng. Trưởng nhóm cũng chịu trách nhiệm rà soát và hoàn thiện bản nộp cuối cùng, đảm bảo tính thống nhất và đầy đủ của toàn bộ đồ án.

Thành viên **Nguyễn Hữu Lộc** (MSSV: 25730038) đã hoàn thành tốt nhiệm vụ xây dựng **chức năng xóa hàng khi đã hoàn thành**. Thành viên đã phát triển thuật toán xóa dòng hiệu quả, bao gồm việc quét từ dưới lên để tìm các dòng đầy, xóa dòng và dịch chuyển các dòng phía trên xuống. Bên cạnh đó, thành viên còn chịu trách nhiệm tổng hợp quá trình làm việc nhóm, ghi nhận các hoạt động, khó khăn và giải pháp trong suốt quá trình phát triển đồ án, góp phần tạo nên tài liệu mô tả quá trình làm việc nhóm đầy đủ và chi tiết.

Thành viên **Trương Anh Khoa** (MSSV: 25730035) đảm nhiệm **thiết kế giao diện trò chơi**, bao gồm bố cục màn hình và trạng thái trò chơi. Thành viên đã tạo ra giao diện rõ ràng, trực quan với các thành phần như border, board, và hiển thị thông tin level, lines, delay. Giao diện được thiết kế phù hợp với đặc trưng của game Tetris cổ điển, góp phần nâng cao trải nghiệm người chơi. Đồng thời, thành viên còn chịu trách nhiệm viết phần đánh giá hợp đồng nhóm này, đảm bảo đánh giá chính xác và công bằng về việc thực hiện nhiệm vụ của từng thành viên.

Thành viên **Nguyễn Đình Đức** (MSSV: 25730017) chịu trách nhiệm phát triển **cấu trúc chương trình và các mô-đun điều khiển**, bao gồm vòng lặp game (game loop), tốc độ rơi và cơ chế tăng dần độ khó. Thành viên đã xây dựng hệ thống quản lý tốc độ game hiệu quả với các hằng số như BASE_DELAY, SPEED_STEP, và LINES_PER_LEVEL, tạo ra cơ chế tăng level tự động khi người chơi xóa được nhiều dòng. Các chức năng này giúp trò chơi vận hành logic, mạch lạc và đúng với đặc trưng của game Tetris cổ điển.

Thành viên **Hoàng Xuân Phong** (MSSV: 25730052) đã thực hiện tốt nhiệm vụ **phát triển chức năng xoay khối khi đang rơi**. Thành viên đã xây dựng hệ thống xoay block với các hàm canRotateBlock() và rotateBlock(), đảm bảo block chỉ xoay khi vị trí sau khi xoay hợp lệ. Chức năng này được tích hợp vào game loop và hoạt động mượt mà với các phím điều khiển. Bên cạnh đó, thành viên còn chịu trách nhiệm tổng hợp các kỹ năng mà nhóm đã sử dụng để hoàn thành báo cáo, góp phần làm rõ các công nghệ, phương pháp và best practices được áp dụng trong dự án.

Nhìn chung, việc thực hiện hợp đồng nhóm được đánh giá là **nghiêm túc, đúng kế hoạch và hiệu quả**. Mỗi thành viên đều hoàn thành tốt nhiệm vụ được phân công, có tinh thần trách nhiệm và hỗ trợ lẫn nhau. Sự phối hợp đồng bộ giữa các thành viên đã góp phần quan trọng vào việc hoàn thành đồ án đúng thời hạn và đạt được các mục tiêu đề ra.

---

**Tác giả:** SS004-Tetris-Game Team - Nhóm 06  
**Ngày:** Tháng 11 năm 2025  
**Phiên bản:** 1.0

