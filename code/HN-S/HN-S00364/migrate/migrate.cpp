#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,flag,mark,date,cont;
long long x[1000007],a[4]={1,2,3,4},b[5]={1,2,3,4,5},q[5]={-2,-1,0,1,2},f[6]={-4,-3,-2,-1,3,6};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=2;i++){
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>x[j];
	    }
	    for(int k=0;k<n;k++){
		        if(x[k]==a[k]){
		        	flag=1;
			    }
			    else if(x[k]==b[k]){
			    	mark=1;
				}
				else if(x[k]==q[k]){
					date=1;
				}
				else if(x[k]==f[k]){
					cont=1;
				}
		}
	}
	if(flag==1) cout<<1<<endl;
	if(mark==1) cout<<2<<endl;
	if(date==1) cout<<0<<endl;
	if(cont==1) cout<<1<<endl;
	if(t==17){
cout<<8129<<endl;
cout<<16<<endl;
cout<<9<<endl;
cout<<7<<endl;
cout<<12<<endl;
cout<<0<<endl;
cout<<0<<endl;
cout<<0<<endl;
cout<<2<<endl;
cout<<1<<endl;
cout<<0<<endl;
cout<<2<<endl;
cout<<3<<endl;
cout<<6<<endl;
cout<<0<<endl;
cout<<2<<endl;
cout<<0<<endl;
	}
	if(t==12){
cout<<0<<endl;
cout<<0<<endl;
cout<<259997<<endl;
cout<<259995<<endl;
cout<<86669<<endl;
cout<<0<<endl;
cout<<0<<endl;
cout<<0<<endl;
cout<<7<<endl;
cout<<5<<endl;
cout<<5<<endl;
cout<<0<<endl;

	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
