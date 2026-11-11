#include<bits/stdc++.h>
using namespace std;
int a,n,cnt,ans,w;
string s,t,e[1000001],d[1000001];
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
    for (int i=1;i<=n;i++){
    	cin>>a>>s;
    	for(int j=0;j<a;j++){
    		t+=s;
		}
	}
	int q;
	if(t.size()%2==0) q=t.size()-1;
	else q=t.size();
	for(int i=0;i<t.size()/2;i++){
		e[i]=t[i];
	}
	for(int i=t.size();i>=q;i--){
		d[w++]=t[i];
	}
	for(int i=0;i<t.size();i++){
		if(e[i]==d[i]) ans=0;
		else{
			ans=1;
			cnt++;
		} 
	}
	if(ans==0){
		cout << 0;
	}
	else cout << cnt;
    return 0;
    }
