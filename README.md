## 📌 목차

- [개요](#개요)
- [프로젝트 설명](#프로젝트-설명)
- [주요 기능 설명](#주요기능_설명)
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

## 주요 기능 설명

| 그룹           | 단축키 | 기능                             | 설명                                          |
| -------------- | :----: | -------------------------------- | --------------------------------------------- |
| **기본 노드 조작** | 1      | Search Node                      | 특정 값 검색                                   |
|                | 2      | Insert Node                      | 연속 범위(시작→끝) 삽입                         |
|                | 5      | Delete Node                      | 연속 범위(시작→끝) 삭제                         |
| **랜덤 노드 조작** | 3      | Insert Random Node (≤9999)       | 0~9998 사이 난수 N개 삽입                      |
|                | 4      | Insert Random Node (≤INT_MAX)    | 31비트 난수 N개 삽입                           |
|                | 6      | Delete Random Node               | 트리에서 랜덤 N개 삭제                         |
| **출력·검사**     | 7      | Print Node Data                  | 중위 순회 결과 값 목록 출력                    |
|                | 8      | Print Path Data                  | 각 리프 경로별 black/red 카운트 출력             |
| **테스트·비교**   | 9      | Test Tree                        | 자동 삽입·삭제 무결성 테스트                    |
|                | 0      | Set Compare Mode                 | RB-Tree ↔ BST 동기화 모드 토글                 |
|                | Q      | Print Compare Result             | RB vs BST 성능 콘솔 출력 및 `output.txt` 저장 |
|                | W      | Shift Tree Drawing               | 화면 트리 드로잉(RB-Tree/BST) 전환             |

---

## 테스트

- **기능 테스트**
    - 수동 입력: 연속 범위(예: 1~N) 또는 랜덤 값 삽입/삭제 후 `PrintNodeData`, `PrintPathData`로 내부 상태 확인
    - 비교 모드 ON/OFF 전환 후 동일 입력 수행 → 삽입·삭제 성능 차이를 콘솔 로그로 비교
- **자동 테스트** (`TestTree` 기능)
    - `rand()`로 생성된 32비트 난수 삽입·삭제를 CHECKPOINT(5,000,000) 단위로 루프 반복
    - `TEST_RETURN::DOUBLE_RED`, `UNBALANCD` 오류 발생 시 즉시 중단 → 균형 검증
    - insert/delete 누적 성공 횟수 및 루프 카운트 결과 출력
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
