#include<bits/stdc++.h>
#define ll long long
using namespace std;
int flag=0;
int n,a[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	string s_sum="";
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];	
		for(int j=1;j<=a[i];j++){
			s_sum+=a[i];
		}
	}
	int len=s.size();
	for(int i=1;i<=len;i++){
		flag=1;//标记变量恢复
		if(s_sum[i]==s_sum[i-1]) {
			flag=1;
		}else{
			flag=0;
		}
	}
//	for(int i=1;i<=len;i++){
//		if(s[i-1]==s[i]){
//			for(i=0;i<=len/2;i++){
//				
//			}
//		}
//	}
	return 0;
}

