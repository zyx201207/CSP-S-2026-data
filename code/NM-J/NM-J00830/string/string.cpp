#include<bits/stdc++.h>
using namespace std;
int sum(std::vector<int> data){
    int result=0;
    for(int i=0;i<data.size();i++)
        result+=data[i];
    return result;
}
int gcd(int a,int b){
    if(a%b==0)return b;
    if(b%a==0)return a;
    for(int i=2;i<=10;i++)
        if(a%i==0&&b%i==0)
            return i*gcd(a/i,b/i);
    return 1;
}
int main(){
    fstream read;
    read.open("string.in",ios_base::in);
    int n;
    read>>n;
    vector<int> num;
    vector<char> data;
    num.resize(n);
    data.resize(n);
    for(int i=0;i<n;i++)
        read>>num[i]>>data[i];
    long long result=0;
    int __num=1;
    for(int i=0;i<num.size()-1;i++)
    __num=gcd(num[i],num[i+1]);
    for(int i=0;i<num.size();i++)
        num[i]/=__num;
    int _sum=sum(num);
    std::string str;
    for(int i=0;i<n;i++)
        for(int j=0;j<num[i];j++)
            str+=data[i];
    n=str.length();
    std::string last;std::string then;
    if(_sum%2==0){
        for(int i=0;i<n/2;i++)
            last+=str[i];
        for(int i=n-1;i>=n/2;i--)
            then+=str[i];
    }else{
        for(int i=0;i<n/2;i++){
            last+=str[i];
        }
        for(int i=n-1;i>=n/2+1;i--){
            then+=str[i];
        }
    }
    int left=0;int right=0;
    for(int i=0;i<last.size();i++){
        if(last[i]!=then[i])
        result++;
    }
    end:
    fstream write;
    write.open("string.out",ios_base::out);
    write<<result*__num;
    return 0;
}