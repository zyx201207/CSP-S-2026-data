#include <iostream>

using namespace std;
//TLE 32

const int N=200005;
int n;
int a[N];
int rea[N];
char c[N];
char rec[N];
long long cnt=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		cnt+=a[i];
		rea[n+1-i]=a[i];
		cin >> c[i];
		rec[n+1-i]=c[i];
	}
	long long cnt1=0,cnt2=0;
	long long mid=(cnt+1)/2;
	long long xba=1,xbrea=1;
	long long midd=mid,ai=a[1],reai=rea[1];
	while(midd>0){
		if(ai==0){
			xba++;
			ai=a[xba];
		}
		if(reai==0){
			xbrea++;
			reai=rea[xbrea];
		}
		if(c[xba]!=rec[xbrea]){
			cnt1++;
		}
		ai--;
		reai--;
		midd--;
	}
	midd=cnt-mid;
	while(midd>0){
		if(ai==0){
			xba++;
			ai=a[xba];
		}
		if(reai==0){
			xbrea++;
			reai=rea[xbrea];
		}
		if(c[xba]!=rec[xbrea]){
			cnt2++;
		}
		ai--;
		reai--;
		midd--;
	}
	cout << min(cnt1,cnt2) << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
