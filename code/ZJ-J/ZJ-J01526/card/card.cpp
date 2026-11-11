#include<bits/stdc++.h>
using namespace std;
int a[210000],b[410000],t[210000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxn=0;
	for(int i=1;i<=n;i++) cin>>a[i],maxn=max(a[i],maxn);
	int l=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=l;k++){
				if(b[k]==a[j]){
					l=k;
					for(int o=k;o<=l;o++){
						b[i]=0;
					}
					break;
				}
			}
			b[l]=a[i];
			l++;
		}
		for(int j=1;j<=l+n-i+1;j++){
			t[b[j]]++;
		}
	}
	for(int i=1;i<=maxn;i++) cout<<t[i]<<" ";
	//wo C le
	//zhe ge bian ji qi ba wo T3 te A dai ma tun le wo zhi neng fang qi le
	return 0;
}                        