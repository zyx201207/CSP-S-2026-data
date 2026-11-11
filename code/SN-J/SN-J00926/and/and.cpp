#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int a[maxn],len,num=0,rec[maxn],lenth[maxn];
string b[maxn],ans;
int main(){
	ans="1";
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		int l=0;
		while(a[i]!=0){
			b[i]+=(a[i]%2+48);
			a[i]=a[i]/2;
			l+=1;
			lenth[i]=l;
		}
		len=max(len,l);
	}
	int lenn=len;
	for(int i=lenn-1;i>=0;i--){
		for(int j=1;j<=n;j++){
			if(b[j][i]=='1'){
				rec[j]=1;
				num++;
			}
		}
		len--;
		if(num>=m)break;
	}
	while(num>m){
		for(int i=len-2;i>=0;i--){
			for(int j=1;j<=n;j++){
				if(rec[j]==0)continue;
				if(b[j][i]=='0'){
					rec[j]=0;
					num--;
					if(num==m)break;
				}
			}
			if(num==m)break;
		}
	}
	for(int i=1;i<=n;i++){
		if(rec[i]==1){
			for(int j=0;j<=lenth[i];j++){
				int k=1;
				for(int q=1;q<=j+1;q++){
					k*=2;
				}
				ans+=k;
			}
		}
	}
	cout<<ans;
	return 0;
}
