#include<iostream>
using namespace std;
int a[20],ans[20];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int m,n;
	int cnt1=0,cnt2=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	
	for(int i=1;i<=m;i++){
		if(a[1]!=a[2]){
			if(a[1]==1||a[2]==1){
				cnt1++;
			}else if(a[1]==2||a[2]==2) cnt2++;
		}
	}
	if(m==1){
		cout << cnt1;
		return 0;
	}else if(m==2){
		cout << cnt2;
		return 0;
	}
	cout << cnt1 << " " <<cnt2;
	return 0;
}
