#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int t[300001];
int a[500001];
int b[500001];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		int l=0;
		for(int j=i;j<=n;j++){
			int p=-1;
			for(int k=1;k<=l;k++){
				if(b[k]==a[j]){
					p=k;
					break;
				} 
			}
			if(l>0&&p!=-1){
				l=p;
			}else{
				b[++l]=a[j];
			}
		}
		for(int j=1;j<=l;j++){
			t[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << t[i] << ' ';
	}
	
	return 0;
}
