#include<bits/stdc++.h>
using namespace std;
string a;
long long sum,cnt;
void x(int s,int u){
	if(s==-1){
		return;
	}
	int w=a[s]-'a'+1;
	int z=a[u]-'a'+1;
	if(w==z){
		sum++;
	}
	x((s-1),(u+1));
}
long long n,m[100005];
char g[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>g[i];
		cnt+=m[i];
		for(int j=0;j<m[i];j++){
			a+=g[i];
		}
	}
	if(cnt%2==0){
		x((cnt/2-1),(cnt/2));
	}
	else{
		x((cnt/2-1),(cnt/2+1));
	}
	cout<<cnt/2-sum;
	return 0;
} 
