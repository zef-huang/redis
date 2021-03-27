# coding=utf8

# ---------------------------------------------------
# 生产者，将任务和参数存储到 redis 6 号数据表
# 存储格式：{"name": "hzf", "age": "13"}
# ---------------------------------------------------


import redis
import json

client = redis.StrictRedis(host='127.0.0.1', port=6379, db=6)

while True:
    name = input("请输入姓名：")
    age = input("请输入年龄：")

    client.lpush('person_queue', json.dumps({'name': name, 'age': age}))
    # break

client.close()