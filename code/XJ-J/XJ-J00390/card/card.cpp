#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int M = 3e5 +5;
int a[N],dui[N];
int tong[M],pos[M];
int n,m,RP=0;
int find_(int x,int t){
    bool flag =0,post=0;
    for(int i =0;i <n;i++){
        if(dui[i] == x){
            flag = 1;
            post = i;
        }

        
    }
    if(flag == 0){
        return -1;
    }else return post;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin.tie(0),cout.tie(0);
	cin >> n >> m;

	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int T = 0;T < n; T ++){
        for(int d = T; d < n; d ++){
        int find__ = find_(a[d],T);
           if (find__ == -1) {
               dui[RP] = a[d];
               RP++;
           }else{
               for(int p = find__;p< n;p++){
                   dui[p] = 0;
               }
               dui[RP] = a[d];
               RP++;
           }
        }	
		for(int ccf = 0;ccf <= RP;ccf++){
			if(dui[ccf]>=1 && dui[ccf]<=m){
				if(pos[ccf] != T+1){
					tong[dui[ccf]]++;
					pos[ccf] = T+1;
				}
			
				dui[ccf] = 0;
			}
			
		}

    }
   for(int tong_ = 1; tong_ <= m;tong_ ++ ){
    	
    	cout << tong[tong_] << " ";
	}
   
	
	//woqu.
	//2026-10-31-10:42
	//wo zhi jie na na ge kuai zi hao ba
	//shuo sha le qian t1 t2 t3 quan bu bao li
	//ccf qiu bao li duo dian fen
	//++RP RP += 111111111
	//2026-10-31-11:30
	//wo qu zhe ge ### t4 wei shen me ppp zuo bu dui
	//2026-10-31-11:54
	//wc!!!!!!!!!!!!!!!!dui le?
	//qwq
	//luogu:zhgbed
	return 0;
	
}