#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	int maxx = -1,n,m;
	cin >> n  >> m;
	vector<int> a(n+5),b(n+5);
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		b[i] = a[i];
	}
	if(m==1){
		sort(b.begin(),b.end());
		cout << b[n];
	}else if(m==2){
		for(int j = 1;j<=n-1;j++){
			for(int g = j+1;g<=n;g++){
				maxx = max(maxx,(a[j]&a[g]));
			}
		}
		cout << maxx;
	}
	else if(m==3){
		for(int j = 1;j<=n-2;j++){
			for(int g = j+1;g<=n-1;g++){
				for(int y = g+1;y<=n;y++){
					maxx = max(maxx,((a[j]&a[g])&a[y]));
				}
			}
		}
		cout << maxx;
	}
	return 0;
}