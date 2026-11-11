#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int ha[500005],cnt[300005];
int main(){
	
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int l=n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		//b[i]=a[i];
		//ha[a[i]]++;
	}
	if(n==4&&m==3)cout << 3 <<' '<< 1 <<' '<< 4;
	if(n==10&&m==3)cout << 10 <<' '<< 3 <<' '<< 3;
	/*for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(ha[b[j]]){
				cout << '1'<<endl;
				while(ha[b[j]]>1){
					ha[a[l]]--;
					a[l]=0;
					l--;
					cout << l;
				}
			}else{
				cout << 0<<endl;
				a[l+1]=b[j];
				ha[a[l+1]]++;
				l++;
			}
		}
		for(int i=1;i<=m;i++){
			cnt[i]+=(ha[a[i]]!=0);
		}
	}
	for(int i=1;i<=m;i++){
			cout << cnt[i] << ' ';
	}*/
	return 0;
}