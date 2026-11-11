#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
long long sum[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    long long l=0;
   long long x=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        l+=a[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    long long cnt=0;
    for(int i=0;i<=l/2;i++){
        if(s[i]!=s[l-1-i]) cnt++;
    }
    cout<<cnt;
    return 0;
}
/*
将各题最终提交的 C++ 源文件直接保存在这个文件夹内,文件名及大小写严格按题
面要求填写,扩展名为 .cpp。例如,若题目要求源文件名为 problem.cpp
*/
