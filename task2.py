from concurrent.futures import ThreadPoolExecutor
import os
from threading import Thread
import time
def main():
    start=time.time()
    a=[]
    b=[]
    count=0
    a=os.listdir()
    k=0
    count=0
    for i in a:
        if '.txt' in i:
            count+=1
            b.append(i)
        
                    
    if(count<10):
        with ThreadPoolExecutor(max_workers = count) as executor:
            executor.map(fileread,b)
            executor.shutdown(wait=True)
    elif(count>10):
        with ThreadPoolExecutor(max_workers = 10) as executor:
            executor.map(fileread,b)
            executor.shutdown(wait=True)
    
    end=time.time()
    timetaken=(end-start)*1000
    timetaken=str(round(timetaken,2))
    print("Timetaken : ",timetaken,"seconds")
    
    
    
def fileread(text):
    f=open(text,"r")
    r=f.read()
    f.close()
    l = r.split()
    l.append('\0')
    k = []
    length=len(l)
    res=' '
    for i in range(length-1):
        if(l[i]!=l[(i+1)]):
            k.append(l[i])
    res=' '.join(k)
    #print(res)

    f2= open(text,"w")
    f2.write(res)
    f2.close()
    
    

if __name__=='__main__':

    main()