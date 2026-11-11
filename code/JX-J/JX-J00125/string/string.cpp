#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
string s;
bool p(string q){
    int l=q.size();
    if(l==1) return true;
    for(int i=1;i<=l;i++){
        for(int j=l;j>=1;j--){
            if(q[i]!=q[j]) return false;
        }
    }
    return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
        long long x;
        string a;
        cin>>x>>a;
        for(int j=1;j<=x;j++)
            s+=a;
	}
	if(n==1){
        cout<<"0";
        return 0;
	}
	else if(n==2){
        if(s[1]!=s[2]) {
            cout<<"1";
            return 0;
        }else{
            cout<<"0";
            return 0;
        }
	}

	for(int i=n;i>=1;i++){
        if(p(s)==true){
            cout<<cnt;
            return 0;
        }else{
            s[i]=s[n-i+1];
            cnt++;
        }
	}
	cout<<0;
	return 0;
}
