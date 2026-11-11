#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a[8];
	string C1, S1, C2, S2;
	cin >> C1 >> S1 >> C2 >> S2;
	if(C1 == C2){
        a[0] = 1;
	}else{
	    a[0] = 0;
	}
	if(S1[1] == S2[1] && S1[2] == S2[2]){
        a[1] = 1;
	}else{
	    a[1] = 0;
	}
	if((S1[1] == S2[1] && S1[2] == S2[2])&&(S1[3]-S2[3]<=2)&&((S1[3]<='c'&&S2[3]<='c')||(S1[3]>'c'&&S2[3]>'c')){
        a[2] = 1;
	}else{
	    a[2] = 0;
	}
	if(((S1[1] == S2[1] && S1[2] == S2[2])&&(S1[3]-S2[3]<=2)&&((S1[3]<='c'&&S2[3]<='c')||(S1[3]>'c'&&S2[3]>'c')))&&(S1[3]-S2[3]==1||S1[3]-S2[3]==-1)){
        a[3] = 1;
	}else{
	    a[3] = 0
	}
	cout << a[0] << a[1] << a[2] << a[3];


	return 0;
}

