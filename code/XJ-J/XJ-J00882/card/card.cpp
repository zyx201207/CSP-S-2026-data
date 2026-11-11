#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10005],desk[1000000],d=1,sum,t[100000000],len=INT_MIN,ans;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		sum=0,ans=0;
		for(int i=1;i<=len;i++){
			t[i]=0;
		}
		len=INT_MIN;
		for(int i=j;i<=m;i++){
			desk[d]=a[j];
			for(int r=i;r<=d;r++){
				for(int e=r+1;e<=d;e++){
					if(desk[d]==desk[r]){
						for(int h=r+1;h<=d;h++){
							desk[h]=desk[h+1];
						}
						d=d-(e-r);
					}
				}
			}
			d++;
			for(int o=1;o<=d;o++){
				sum+=desk[o];
			}
			t[sum++];
			cout<<t[sum];
			len=max(len,sum);
			for(int o=1;o<=len;o++){
				if(t[o]!=0){
					ans++;
				}
			}
			cout<<ans<<' ';
		}
	}
	return 0;
}