#include<bits/stdc++.h>
using namespace std;
#define int long long

int m;
int a[200010],b[200010],ans;
char c[200010],d[200010];

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>c[i];
		
		if(c[i]==c[i-1]){
			a[i-1]+=a[i];
			i--;
			m--;
		}
	}
	
	for(int i=1;i<=m;i++){
		b[i]=a[m-i+1];
		d[i]=c[m-i+1];
	}
	
//	cout<<'a';
//	for(int i=1;i<=m;i++){
//		cout<<a[i]<<' ';
//	}cout<<"\nc";
//	for(int i=1;i<=m;i++){
//		cout<<c[i]<<' ';
//	}cout<<"\nb";
//	for(int i=1;i<=m;i++){
//		cout<<b[i]<<' ';
//	}cout<<"\nd";
//	for(int i=1;i<=m;i++){
//		cout<<d[i]<<' ';
//	}cout<<endl;
	
	for(int i=1,j=1;i<=m&&j<=m;){
//		cout<<i<<' '<<j<<' ';
		
		if(c[i]==d[j]){
			if(a[i]==b[j]){
				a[i]=0;
				b[i]=0;
				i++;
				j++;
			}
			else if(a[i]>b[j]){
				a[i]-=b[j];
				b[j]=0;
				j++;
			}
			else {
				b[j]-=a[i];
				a[i]=0;
				i++;
			}
		}
		else{
			if(a[i]==b[j]){
				ans+=a[i];
				a[i]=b[j]=0;
				i++;
				j++;
			}
			else if(a[i]>b[j]){
				a[i]-=b[j];
				ans+=b[j];
				b[j]=0;
				j++;
			}
			else {
				b[j]-=a[i];
				ans+=a[i];
				a[i]=0;
				i++;
			}
		}
//		cout<<ans<<endl;
	}
	
//	cout<<"\na";
//	for(int i=1;i<=m;i++){
//		cout<<a[i]<<' ';
//	}cout<<"\nc";
//	for(int i=1;i<=m;i++){
//		cout<<c[i]<<' ';
//	}cout<<"\nb";
//	for(int i=1;i<=m;i++){
//		cout<<b[i]<<' ';
//	}cout<<"\nd";
//	for(int i=1;i<=m;i++){
//		cout<<d[i]<<' ';
//	}cout<<"\n";
	
	cout<<ans/2;

	return 0;
}
//aaaaa bbbb c ccc d dddd fffff
//fffff dddd d ccc c bbbb aaaaa

//aaaaa bbbb cccc ddddd fffff
//fffff ddddd cccc bbbb aaaaa

/*5
5 a
4 b
4 c
5 d
5 f*/
