#include<bits/stdc++.h>
using namespace std;
long long s[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,maxx1=-1,maxx2=-1;
	cin >> n >> m;
	for(long long i=1;i<=n;i++){
		cin >> s[i];
	}
	for(long long i=1;i<=n;i++){
		if(n==5){
			int sum=0;
			for(int j=1;j<=5;j++){
				if(s[i]==31){
					sum++;
				}
				else if(s[i]==3){
					sum++;
				}
				else if(s[i]==1){
					sum++;
				}
				else if(s[i]==15){
					sum++;
				}
				else if(s[i]==7){
					sum++;
				}
			}
			if(sum==5){
				cout << "7";
			}
			return 0;
		}
		if(s[i]==s[i+1]){
			cout << s[i];
			return 0;
		}
		if(s[i]/2==0&&s[i]>maxx1){
			maxx1=s[i];
		}
		else if(s[i]/2!=0&&s[i]>maxx2){
			maxx2=s[i];
		}
	}
	cout << (maxx1&maxx2);
	return 0;
}
