#include <bits/stdc++.h>
using namespace std;

int a[100005];
bool cole[100005];
int ak[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	int n,m;
	cin >> n >> m;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}

	vector<int> ap;
	int g = 0;
	for (int i=1; i<=n; i++){
		for (int j=i; j<=n; j++){
			if (cole[ap[g]] == true){
				for (int k=j; a[k]; k++){
					ap.clear();
					g = 0;
					ap.push_back(a[k]);
					g++;
				}
			}else{
				ap.push_back(a[j]);
				cole[ap[g]] = true;
				g++;
			}
		}
		for (int ad=0; ad<ap.size(); ad++){
			ak[ad]++;
		}
	}

	for (int i=1; i<=m; i++){
		if (ak[i] != 0){
			cout << ak[i];
		}
	}

	return 0;
}
