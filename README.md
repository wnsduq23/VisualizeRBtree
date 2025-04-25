## 📌 목차

- [개요](#개요)
- [프로젝트 설명](#프로젝트-설명)
- [테스트](#테스트)
- [폴더 구조](#폴더-구조)

---

## 개요

- **프로젝트 이름**: 레드블랙 트리 시각화 도구
- **개발 기간**: 2024.11 ~ 2024.12
- **개발 언어**: C++ , GDI
- **개발 인원**: 1명

---

## 프로젝트 설명

이 프로젝트는 Red–Black Tree와 일반 Binary Search Tree의 동작 원리 및 성능 차이를 시각적으로 비교하고, 대규모 삽입·삭제 테스트를 통해 균형 유지 로직의 안정성을 검증하기 위해 제작되었다.

- Win32 메시지 루프 기반으로 키 입력(숫자 키, 방향키, Q/W 등)만으로 삽입·삭제·검색·랜덤 테스트 기능을 제공
- GDI를 활용한 이중 버퍼링(Compatible Bitmap + 메모리 DC)으로 깜빡임 없는 트리 드로잉
- PROFILE 매크로 기반으로 삽입·삭제 연산마다 수행 시간을 측정해 로그 출력
- 비교 모드(Compare Mode) 활성화 시, 두 트리를 나란히 화면에 그려서 균형 유지 차이를 한눈에 확인

---

## 폴더 구조
<pre>
📦 VisualizeRBTree
┣ 📂Framework           # Win32 API 및 공통 헤더
┃  ┣ 📜 framework.h
┃  ┗ 📜 targetver.h
┣ 📂Config              # 트리 그리기 설정
┃  ┗ 📜 TreeSetting.h
┣ 📂Core                # 자료구조(트리) 구현
┃  ┣ 📜 RedBlackTree.h
┃  ┗ 📜 BinaryTree.h
┣ 📂Tester              # 테스트·비교 로직
┃  ┣ 📜 TreeTester.h
┃  ┗ 📜 TreeTester.cpp
┣ 📂UI                  # 윈도우 메시지 루프 & GDI 드로잉
┃  ┣ 📜 Main.h
┃  ┗ 📜 Main.cpp
┣ 📂Resource            # 리소스 정의
┃  ┗ 📜 Resource.h
┗ 📂Profile             # 성능 측정 매크로
   ┗ 📜 Profile.h

</pre>
