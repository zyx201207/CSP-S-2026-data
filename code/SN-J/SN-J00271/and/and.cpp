#include <bits/stdc++.h>
using namespace std;
int sh_er(int x){
	int ans=0;
	while(x){
		int a=x/2;
		ans=ans*10+x-2*a;
		x/=2;
	}
	return ans;
}

int awy(int x,int y){//x,yΪB 
	int ans=0;
	int zzc=1;
	while(x && y){
		if(x%10==1 && y%10==1) ans=ans*10+1; 
		else {
			if(ans!=0) ans*=10;
			else zzc++;
		}
		x/=10;
		y/=10;
	}
	if(zzc==1) return ans;
	else return ans*pow(10,zzc-1);
}

bool cmp(int x,int y){
	return x>y;
} 
int main(){
	int n,m;
	int arr[100005];
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	sort(arr+1,arr+n+1,cmp); 
	cout<<awy(sh_er(arr[1]),sh_er(arr[2]));
	//cout<<12;
	return 0;
} 

