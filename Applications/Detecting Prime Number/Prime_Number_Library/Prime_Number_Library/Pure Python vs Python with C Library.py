import ctypes
import time
import os

# 1. 내가 만든 C 라이브러리 로드 (DLL 파일 경로)
# (같은 폴더에 있음)
lib_path = os.path.abspath("prime_lib.dll")
print("DLL path:", lib_path)  # 실제로 어떤 경로를 보는지 확인
c_lib = ctypes.CDLL(lib_path)
# C함수의 리턴 타입과 인자 타입 설정 (안전장치)
c_lib.is_prime.argtypes = [ctypes.c_int]
c_lib.is_prime.restype = ctypes.c_int

# 2. 파이썬으로 짠 똑같은 함수
def py_is_prime(n):
    if n < 2: return 0
    i = 2
    while i * i <= n:
        if n % i == 0: return 0
        i += 1
    return 1

# 3. 시간내기: 1부터 1억까지 소수 찾기
NUM = 10000000 

print(f"🔥 대결 시작 (0 ~ {NUM}) 🔥")

# [Round 1] Python Native
start = time.time()
count_py = 0
for i in range(NUM):
    if py_is_prime(i):
        count_py += 1
print(f"Python: {time.time() - start:.4f}초 소요 (개수: {count_py})")

# [Round 2] C Library (Ji-sang's Engine)
start = time.time()
count_c = 0
for i in range(NUM):
    if c_lib.is_prime(i):
        count_c += 1
print(f"C Lib : {time.time() - start:.4f}초 소요 (개수: {count_c})")