#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string R_chexiang,R_zuowei,X_chexiang,X_zuowei;
    cin >> R_chexiang >> R_zuowei >> X_chexiang >> X_zuowei;

    char R_pai1 = R_zuowei[0];
    char R_pai2 = R_zuowei[1];
    char X_pai1 = X_zuowei[0];
    char X_pai2 = X_zuowei[1];

    char R_zuo = R_zuowei[2];
    char X_zuo = X_zuowei[2];

    int tongchexiang = 0;
    int tongpai = 0;
    int tongyice = 0;
    int xianglin = 0;

    if(R_chexiang == X_chexiang){
        tongchexiang = 1;
        if(R_pai1 == X_pai1 && R_pai2 == X_pai2){
            tongpai = 1;
            if(R_zuo == 'A'){
                if(X_zuo == 'B'){
                    tongyice = 1;
                    xianglin = 1;
                }
                else if(X_zuo == 'C'){
                    tongyice = 1;
                }
            }
            else if(R_zuo == 'B'){
                if(X_zuo == 'A' || X_zuo == 'C'){
                    tongyice = 1;
                    xianglin = 1;
                }
            }
            else if(R_zuo == 'C'){
                if(X_zuo == 'B'){
                    tongyice = 1;
                    xianglin = 1;
                }
                else if(X_zuo == 'A'){
                    tongyice = 1;
                }
            }
            else if(R_zuo == 'D'){
                if(X_zuo == 'F'){
                    tongyice = 1;
                    xianglin = 1;
                }
            }
            else if(R_zuo == 'F'){
                if(X_zuo == 'D'){
                    tongyice = 1;
                    xianglin = 1;
                }
            }
        }
    }
    cout << tongchexiang << tongpai << tongyice << xianglin;
    return 0;
}
