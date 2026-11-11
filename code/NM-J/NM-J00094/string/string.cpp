#include<bits/stdc++.h>
using namespace std;
freopen("string.in","r",strin);
freopen("string.out","w",strout);
int main(){
    int n=0,ans=0;
    long long a[1001];
    char b[1001];
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++){
            s+=b[i];
        }
    }
    if(s.size()%2==0){
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-i-1]){
                ans+=1;   
            }
        }
    }else{
   		for(int i=0;i<s.size()/2;i++){
           	if(s[i]!=s[s.size()-i]-1){
            	ans+=1;
        	}
       	}
   	}
    cout<<ans<<endl;
    return 0;
}
