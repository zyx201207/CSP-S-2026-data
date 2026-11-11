#include<bits/stdc++.h>
using namespace std;
int d,tot;
int n,m;
void judge(int crys[500005],int n){
	int tmp;
	tmp+=crys[d]-crys[d-n];
	if(n>d){
		return;
	}
	if(tmp<m){
		if(crys[d]-crys[d-n]!=0){
			tot+=1;	
		}
		
		judge(crys, n+1);
	}
	
	return;
	
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    int crys[500005];
    int ans=0;

    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>crys[i];
    }
    sort(crys,crys+n);
    for(int i=n-1;i>=0;i--){
    	d=n;
    	tot=0;
    	judge(crys,1);
    	if(tot>ans){
    		ans=tot;
		}
	}

	cout<<tot;

    return 0;}

