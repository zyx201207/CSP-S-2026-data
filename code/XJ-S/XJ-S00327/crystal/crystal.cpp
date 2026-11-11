#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500050],k=0,st=1;
bool flag=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	
	
	//ÊäÈë 
    cin >> n >> m;
    for(ll i=0;i<n;i++){
    	cin >> a[i];
	}
	
	
	//main 
	sort(a,a+n);
	while(m>0){
		if((m-st)<0){
			flag=1;
			break;
		}
		while(a[k]==a[k+1]){
			st++;
			k++;
		}
		m-=st;
		a[st-1]++;
	}
	
	if(flag==1){
//		cout << "\n---------1---------\n";
		ll tat=k+1,hm=0;
		while(a[tat]==a[tat+1]){
			hm++;
			tat++;
		}
//		cout << "hm:" << hm << " st-m:" << st-m << "\n";
		if((st-m)<hm){
//			cout << "\n--------1.1--------\n";
			st=m+hm;
		}
	}else{
//		cout << "\n---------2---------\n";
		while(a[k]==a[k+1]){
			st++;
			k++;
		}
	}
	
	
	//²âÊÔ 
//	for(ll i=0;i<n;i++){
//    	cout << a[i] << " ";
//	}
//	cout << "\nm:" << m << " k:" << k << " st:" << st << "\n";
	
	
	//Êä³ö 
	cout << st;
	
	
    fclose(stdin);
    fclose(stdout);
    return 0;
}
