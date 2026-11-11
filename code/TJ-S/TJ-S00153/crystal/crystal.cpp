#include <bits/stdc++.h>
using namespace std;
int n,m,ad=1,num=1;
int h[500005];
void choise(int a){
	for (int j=a-1;j>=0;j--){
		if (h[j]>h[j+1]){
			swap(h[j],h[j+1]);
		}
		else{
			return ;	
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=0;i<n;i++){
		cin >> h[i];
		if (n<=5000){
			choise(i);			
		}
	}
	for (int i=0;i<n;i++){
		
		int hh[i-1],mm=m;
		for (int j=i;j>=0;j--){
			hh[j]=h[i]-h[j];
		}
		for (int j=i-1;j>=0;j--){
			if (mm<hh[j]) break;
			mm=mm-hh[j];
			num++;
		}
		ad=max(ad,num);
		num=1;
	}	
	cout << ad;
	return 0;
}
