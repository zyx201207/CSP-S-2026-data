#include <bits/stdc++.h>
using namespace std;
int a[500005],b[500005],l[500005],s[500005],k=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,x;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){b[k++]=a[j];
			for(int j=1;j<k;j++){
			cout << a[j] << " ";
		}
		cout << endl;
			if(l[a[j]]){
				cout << "a";
				k=l[a[j]];
			}
			else {
				cout << "b";
				l[a[j]]=k;
			}
			
			//cout << k << " " << j<< endl;
		}
		for(int j=1;j<k;j++){
			//cout << a[j] << " ****";
			s[a[j]]++;
		}
		//cout << endl;
		memset(l,0,sizeof(l));
		memset(b,0,sizeof(b));
	}
	for(int i=1;i<=m;i++)
		cout << s[i] << " ";
	return 0;
}
