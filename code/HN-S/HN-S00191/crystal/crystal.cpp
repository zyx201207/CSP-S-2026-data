#include<bits/stdc++.h>
using namespace std;
const int A=5e5+5;
int n,m,a[A],sum[A],cnt=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}int l=1;
	while(m>0){
		int c;
		for(int i=l;i>=1;i--){
			c=sum[i+1]-sum[i];
			if(m<c){
				m=0;
				break;
			}
			sum[i]++;
			m--;
		}
		l++;
		cnt++;
	}
	cout<<cnt;
	return 0; 
}//这题拿个十来分得了，我坐在这里显得很呆，还是打字消遣一下吧 
