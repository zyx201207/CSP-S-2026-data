#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100005][35],b[100005];

int ji[100005];
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		long long shu;
		cin >> shu;
		b[i] = shu;
		long long lll = 0;
		while(shu > 0){
			int yu = shu % 2;
			
			a[i][34-lll] = yu;
			
			shu /= 2;
			lll += 1; 
		}
	
	}
	for(int i = 0;i <= 34;i++){
		long long ci = 0;
		int kkk = 1;
		for(long long j = 1;j <= n;j++){
			if(ji[j] == 2 && a[j][i] == 0){
				kkk = 0;
			}else{
				if(a[j][i] == 1){
				    ci++;
				    ji[j] = 1;
			    }
				
			}
			
		}
		yu = 2;
		for(long long j = 1;j <= n;j++){
			if(ji[j] == 2){
				yu == 1;
			}
		}
		
		if(ci >= yu && kkk == 1){
			
		
			m -= ci;
	
		}
		
		
		for(long long j = 1;j <= n;j++){
			if(ji[j] == 1){
				ji[j] = 2;
			}
		} 
		if(m = 0){
			break;
			
		}
	}
	if(m > 0){
		cout << 0;
	}else{
		int p;
		for(int i = 1;i <= n;i++){
			if(ji[i] == 2);
			p = b[i];
			break;
			
		}
		for(int i = 1;i <= n;i++){
			if(ji[i] == 2){
				p &= b[i];
			}
	
		
			
		}
		cout << p;
		
	}



	
	
}
