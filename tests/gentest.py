import argparse
import pathlib
import random

CWD = pathlib.Path(__file__).parent

veg = [x.title() for x in (CWD / "veg.txt").read_text().strip().split("\n")]

ap = argparse.ArgumentParser()
ap.add_argument("-l", "--length", help="How long is the grocer testfile")
args = ap.parse_args()

tfh = open("grocer.txt", "w")

for _ in range(int(args.length)):
    tfh.write(random.choice(veg)+"\n")
tfh.close()
