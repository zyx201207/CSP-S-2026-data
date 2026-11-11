#include <bits/stdc++.h>
using namespace std;
int p[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	vector<int> a(n);
	int maxx=0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]>maxx){
			maxx=a[i];
		}
	}
	for(int i=0;i<n;i++){
		vector<int> b(maxx);
		int q=0;
		for(int j=i;j<n;j++){
			int o=0;
			for(int k=0;k<q;k++){
				if(b[k]==a[j]){
					o++;
					q=k;
					break;
				}
			}
			if(o==0){
				b[q]=a[j];
			}
			else{
				b[q]=a[j];
			}
			q++;
		}
		q--;
		for(int j=0;j<=q;j++){
			p[b[j]]++;
		}
	}
	for(int i=1;i<=maxx;i++){
		cout << p[i] << " ";
	}
	return 0;
}