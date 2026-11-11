#include <bits/stdc++.h>
using namespace std;

int n,m,z,l,h[200007],a[200007],b[200007];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		l = 0;
		for(int j=i;j<n;j++){
			z = 0;
			if(z = 0){
				b[j] = a[j];
			}
			for(int p=j;p<n;p++){
				if(b[p] == a[j]){
					z = 1;
					for(int c=p;c<j;c++){
						b[c] = 0;
						b[c+1] = a[j];
					}
				}
			}
			l++;
		}
		for(int g=1;g<=m;g++){
			for(int o=i;o<n+i;o++){
				if(b[o] == g){
					h[g] ++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout << h[i] << " ";
	}
}
