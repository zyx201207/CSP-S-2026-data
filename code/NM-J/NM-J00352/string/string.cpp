#include<bits/stdc++.h>
using namespace std;
const long long N =2e5+10;
long long n;
long long a1;
char c1;
string s;
long long cnt;
struct node{
	int a;
	char c;
};
node arr[N];
map<char,int>mp;
long long pre[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a1>>c1;
		arr[i].a=a1;
		arr[i].c=c1;
		mp[c1]+=a1;
		pre[i]=pre[i-1]+a1;
	}
	if(mp.size()==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=(n+1)/2;i++){
		int fa=arr[i].a;
		char fc=arr[i].c;
		int ba=arr[n-i+1].a;
		char bc=arr[n-i+1].c;
		if(fa==ba && fc==bc)continue;
		if(fc!=bc){
			cnt+=max(fa,ba);
			continue;
		}
		if(fc==bc && fa!=ba){
			if(abs(pre[n-i+1]-pre[i]-1)<abs(fa-ba)){
				cnt+=abs(pre[n-i+1]-pre[i]-1);
			}else cnt+=abs(fa-ba); 
		}
	}
	cout<<cnt;
	return 0;
}
