# coding=utf8

# ---------------------------------------------------
# 消费者
# 取出 6 号数据中到数据，打印名字和年龄
# ---------------------------------------------------

import redis
import json

client = redis.StrictRedis(host='127.0.0.1', port=6379, db=6)

while True:
    if client.llen('person_queue'):
        bdata = client.rpop('person_queue')
        person_dict = json.loads(bdata.decode())
        print(person_dict['name'], person_dict['age'])




