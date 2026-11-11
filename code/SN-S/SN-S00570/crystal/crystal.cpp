#include<bits/stdc++.h>
using namespace std;
#define int long long
int A[500010],N,M,S[500010],dengcha,D,ANS,panduan,tNUM,ttNUM;
int ttmid,ttLeft,ttRight;
signed main(){
	freopen("crystal.in","r",stdin);
	ios::sync_with_stdio(0);
	cout.tie(0);cin.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		cin>>A[i];
	}
	sort(A+1,A+N+1);
	for(int i=1;i<=N;i++)S[i]=S[i-1]+A[i];
	/*dengcha=N*(A[1]+A[N])/2;
	if(dengcha==S[N]){
		D=A[2]-A[1];
		int i=1;
		while(1){
			panduan=i*D+i*D*(i-1)/2;
			if(panduan>M){
				i--;
				break;
			}
			i++;
		}
		cout<<i+1;
		return 0;
	}*/
	//cout<<endl;
	ttLeft=1,ttRight=N;
	while(ttLeft<ttRight){
		bool testzz=0;
		ttmid=(ttLeft+ttRight)/2;
		for(int i=0;i<N-ttmid;i++){
			tNUM=S[i+ttmid]-S[i]+M;
			tNUM/=ttmid;
			//cout<<tNUM<<" "<<A[i+ttmid+1]<<" "<<ttmid<<endl;
			if(tNUM>=A[i+ttmid+1]){
				testzz=1;
				ANS=ttmid+1;
				break;
			}
		}
		if(testzz==1){
			ttLeft=ttmid+1;
		}else{
			ttRight=ttmid;
		}
	}
	freopen("crystal.out","w",stdout);
	cout<<ANS;
	return 0;
}
