#include<bits/stdc++.h>
using namespace std;
int n;
long long num[500005],m,ans=1,cnt=0,tail=1;
//bool cmp(string A,string B){
//	if(A>B){
//		return A>B;
//	}if(A<B){
//		return A<B;
//	}return A>B;
//}
//string add(string a,string b){
//	int x=0,y=0,p=a.size(),q=b.size();
//	int w=1,z=1;
//	string c;
//	if(a[0]=='-')w=-1;
//	if(b[0]=='-')z=-1;
//	while(x<p or x<q){
//		int k=0;
//		if(p-x>=0 and a[p-x]!='-'){
//			k=k+
//		}
//	}
//}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}sort(num+1,num+n+1);
	for(int i=2;i<=n;i++){		
		if((cnt+(num[i]-num[i-1])*(i-tail))<=m){
			ans=max(i-tail+1,ans);
			cnt=cnt+(num[i]-num[i-1])*(i-tail);
		}else{
			while(tail<i and (cnt+(num[i]-num[i-1])*(i-tail))>m){
				cnt=cnt-(num[i-1]-num[tail]);
				tail++;
			}cnt+=(num[i]-num[i-1])*(i-tail);
			ans=max(ans,i-tail+1);
		}
	}cout<<ans<<endl;
	return 0;
}
