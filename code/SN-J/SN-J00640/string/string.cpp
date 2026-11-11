// 李思齐 陕西省西安爱知中学 SN-J00640 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct ids{
	char nt;
	ll x;
};
char b,m;
ll n,a,cnt=0,ity=0,changed=0;
ids num[200050]={};
ids ame[200050]={},bme[200050]={};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n; 
	for(int i=1;i<=n;i++){
		cin>>a>>m;
		num[i].x=a;
		num[i].nt=m;
		cnt+=a;
	}
		
	if(cnt%2)ity=cnt/2+1;
	else ity=cnt/2;
	ll batt=0,ity_1=ity,i=0,oldi=0;
	while(ity_1>=0){
			i++;
			ity_1-=num[i].x;
	}
	ity_1+=num[i].x;
	if(ity_1==0)i--;
	//cout<<i<<" "<<ity_1;
	batt=i;
	oldi=i;
	if(cnt%2){	
		while(ity>1){
			if(ity_1==0){
				ity_1=num[i-1].x-num[2*batt-i+1].x;
				i--;
				ity-=num[i].x;
				if(num[i].nt!=num[2*batt-i].nt)changed+=num[i].x;
				oldi=2*batt-i;
				while(ity_1<0){
					i--;
					ity_1+=num[i].x;
					ity-=num[i].x;
					if(num[i].nt!=num[oldi].nt)changed+=num[i-1].x;
				}
			}else{
				ity_1=ity_1-num[2*batt-i+1].x;
				i--;
				ity-=num[i].x;
				if(num[i].nt!=num[i+1].nt)changed+=num[i].x;
				oldi=2*batt-i;
				while(ity_1<0){
					i--;
					ity_1+=num[i].x;
					ity-=num[i].x;
					if(num[i].nt!=num[oldi].nt)changed+=num[i-1].x;
				}
			}
		}
	}else{
		while(ity>0){
			if(ity_1==0){
				ity_1=num[i].x-num[2*batt-i+1].x;
				ity-=num[i].x;
				if(num[i].nt!=num[2*batt-i+1].nt){
					changed+=num[i].x;
					//cout<<changed; 
				}
				//cout<<num[i].nt<<" "<<num[2*batt-i+1].nt<<"\n";
				oldi=2*batt-i;
				while(ity_1<0){
					i--;
					ity_1+=num[i].x;
					ity-=num[i].x;
					if(num[i].nt!=num[oldi].nt)changed+=num[i-1].x;
				}
				i--;
			}else{
				ity_1=ity_1-num[2*batt-i+1].x;
				
				ity-=num[i].x;
				if(num[i].nt!=num[2*batt-i+1].nt)changed+=num[i].x; 
				//cout<<num[i].nt<<" "<<num[2*batt-i+1].nt<<"\n";
				oldi=2*batt-i;
				while(ity_1<0){
					i--;
					ity_1+=num[i].x;
					ity-=num[i].x;
					if(num[i].nt!=num[oldi].nt)changed+=num[i-1].x; 
				}
				i--;
			}
		}
	}
	cout<<changed;
	return 0;
}
/*
6
1000000 a
1000000 a
1000000 a
1000000 b
1000000 b                                                                    
1000000 b                                                                     

2
2 a
3 a
*/
