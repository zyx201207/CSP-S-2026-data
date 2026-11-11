#include <bits/stdc++.h>
using namespace std;
int a[200001];
int canuse[200001];
int b[200001];
int maxs(int m,int w){
	int big = 1,jilu=0;
	for(int i ;i<=200001;i++){
		if(m>1){
			if(maxs(m-1,w&canuse[i])>=big){
				big = maxs(m-1,w&canuse[i]);
			
			}
		}
		else{
			return w;
			break;
		}
	}

	return big;
}


int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,ls=0;
	cin >> n >> m;
	for(int i = 0;i<m;i++){
		cin >> a[i];
		canuse[i]=a[i];
	}
	if(m>1){
	
	for(int h = 0;h<=200001;h++){
		if(maxs(m,a[h])>ls){
			ls = maxs(m,a[h]);
		}
	}
	cout << ls;
	}
	else{
		for(int i = 0;i<=200001;i++){
			if(a[i]>ls){
				ls=a[i];
			}
		}
		cout << ls;
	}
	
	
	return 0;
}
