#include "bits/stdc++.h"
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
    string som;
	long long s;
	char w;
	long long sum = 0;
	long long su =0;
	long long y = 0;
	long long x = 0;
	for(long long i = 1;i <= n;i++){
		cin >> s;
		sum = sum + s;
		cin >> w;
		su = su + s;
		for(long long j=(sum-s);j<=su-1;j++){
			som[j]=w;
		}
	}
	string so;
	long long l = 0;
	for(long long i=su-1;i>=0;i--){
		so[l]=som[i];
		l++;
	}
		if(su%2==1){
			for(long long i=0;i<=su/2;i++){
				if(som[i]!=so[i]){
						y++;
					}
					if(som[i]!=so[i]){
						x++;
					}
				}
			}
		cout <<min(x,y);
	return 0;
} 
