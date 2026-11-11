#include<bits/stdc++.h>
using namespace std;
int n;
int a;
long long ans,wei;
string c;
string s="";
int main(){
    freopen("string.1","r",stdin);
    freopen("string.2","w",stdout);
    cin>>n;
    while(n--){
        cin>>a;
        cin>>c;
        wei+=a;
        while(a--)s+=c;
    }
    string sum=s;
    reverse(sum.begin(),sum.end());
    for(int i=0;i<wei/2;i++){
	    if(s[i]!=sum[i])ans++;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
