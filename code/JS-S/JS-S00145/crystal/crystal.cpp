#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+1+n);
	int daan=0;
	for(int i=n;i>=1;i--){
		int jishu=1;
		bool flag=true;
		int x=m;
		for(int j=i-1;j>=1&&flag;j--){
			int cha=a[i]-a[j];
			if(x-cha>=0){
				x-=cha;
				jishu++;
			}else{
				flag=false;
			}
		}
		daan=max(daan,jishu);
	}
	cout <<daan<<endl;
	return 0;
}
