#include<bits/stdc++.h>
using namespace std;
char c[10000010];
long long n,le=0,l=0,r,a,mid=0,ans=0,anss=0;
char x;
bool ci=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>x;
		for(int j=le+1;j<=le+a;j++){
			c[j]=x;
		}
		le+=a;
	}
	mid=le/2+1;
	if(le%2==1){
		ci=1;
	}else{
		ci=0;
	}
//	for(int i=1;i<=le;i++){
//		cout<<c[i];
//	}
//	cout<<";"<<le<<'\n';
	l=1,r=le;
	while(1){
		if(l==mid){
			break;
		}
		if(c[l]!=c[r]){
			ans++;
		}
//		cout<<c[l]<<" "<<c[r]<<'\n';
		l++;
		r--;
	}
	cout<<ans;
	return 0;
} 
