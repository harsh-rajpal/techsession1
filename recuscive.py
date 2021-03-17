# a=int(input())
# b=int(input())
# def gcd(a, b):
#     if(b==0):
#         return a;
#     else:
#         return gcd(b,a%b);    


# c=gcd(a,b) 
# print(c)       

# def func(a,i,n):
#     if(i==n):
#         return ;
#     else:
#         func(a,i+1,n)
#         print(a[i])    


# n=5
# a="hello"
# i=0

# func(a,i,= 0
counter =0
def calc(a,b):
    
    global counter += 1
    if b==3:
        return(a*a*a);

    else:
        c=calc(a,b/3)
        return(c*c*c);

print(calc(4,81))


