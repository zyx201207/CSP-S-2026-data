freopen("string.in","r",stdin)
freopen("string.out","w",stdout)
#include<bits/stdc++.h>
using namespace std;
int n,ans;
queue<char>q;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			q.push(c);
		}
	}
	if(q.size()%2==0){
		int f=q.size()/2;
		for(int i=1;i<=q.size()/2;i++){
			if(q[i]!=q[f]) ans++;
			f--;
		}
	}else{
		int f=q.size()-1/2;
		for(int i=1;i<=q.size()-1/2;i++){
			if(q[i]!=q[f]){
				ans++;
			}
			f--;
		}
	}
	cout<<ans;
	return 0;
}
