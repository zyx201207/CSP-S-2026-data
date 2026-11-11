#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	long long sum;
	char k;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >> a[i].sum >> a[i].k;
	}
	int i=1,j=n;
	long long ans=0;
	while(i<j){
		if(a[i].k!=a[j].k){
			if(a[i].sum>a[j].sum){
				ans+=a[j].sum;
				a[i].sum-=a[j].sum;
				j--;
			}
			else if(a[j].sum>a[i].sum){
				ans+=a[i].sum;
				a[j].sum-=a[i].sum;
				i++;
			}
			else{
				ans+=a[i].sum;
				i++,j--;
			}
		}
		else{
			if(a[i].sum>a[j].sum){
				j--;
				a[i].sum-=a[j].sum;
			}
			else if(a[j].sum>a[i].sum){
				i++;
				a[j].sum-=a[i].sum;
			}
			else i++,j--;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
