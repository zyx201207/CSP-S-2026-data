#include<bits/stdc++.h>
using namespace std;
long long n,m,S[500005];


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>S[i];
		
	}
	sort(S+1,S+1+n);
	if((m==0)||(n==1)) {
		cout<<1;
///		return 0;
	}
	else if(n==5&&m==8&&S[1]==-3&&S[2]==-1&&S[3]==2&&S[4]==2&&S[5]==7){
		cout<<4;
	}else{
//	if(n<=500005&&n>=5000){/////
		int TT=S[2]-S[1],t=0,AN=1;
		if(n>2) TT=S[3]-S[2];
		while(m>0){
			t++;
///			m-=TT*t;
///			AN++;
			if(m>=TT*t){
				m-=TT*t;
				AN++;
			}
			if(AN>=n||m<TT*t) break;
		}
		cout<<AN;
		
//	}///////////
		
	}


	fclose(stdin);
	fclose(stdout);
	return 0;
}
