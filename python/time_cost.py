# ref: https://gist.github.com/yipo/ab398242cefc70bf59251607faf5d914

import time
from contextlib import contextmanager
from datetime import timedelta


@contextmanager
def time_cost():
    begin = time.time()
    try:
        yield
    finally:
        print('time cost:', timedelta(seconds=time.time() - begin))


if __name__ == '__main__':
    with time_cost():
        sum(range(1000000))
