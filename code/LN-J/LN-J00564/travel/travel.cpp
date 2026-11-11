#include<bits/stdc++.h>
using std::pair;
using std::make_pair;
using std::abs;
char car1_in[11] , sit1_in[11] , car2_in[11] , sit2_in[11] ;
int to_number(char x){
    if(x<='D') return x-'A'+1;
    return 5;
}
bool same_side(int x,int y){
    if(1<=x && x<=3 && 1<=y && y<=3) return true;
    if(4<=x && x<=5 && 4<=y && y<=5) return true;
    return false;
}
bool great(int x,int y){
    if(abs(x-y)>1) return false;
    if(!((x==3 && y==4) || (x==4 && y==3))){
        return true;
    }
    return false;
}
int car1 , car2 ;
pair<int,int> sit1 , sit2 ;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s%s%s%s",car1_in+1,sit1_in+1,car2_in+1,sit2_in+1);
    car1=10*(car1_in[1]-'0')+(car1_in[2]-'0');
    car2=10*(car2_in[1]-'0')+(car2_in[2]-'0');
    sit1=make_pair(10*(sit1_in[1]-'0')+(sit1_in[2]-'0'),to_number(sit1_in[3]));
    sit2=make_pair(10*(sit2_in[1]-'0')+(sit2_in[2]-'0'),to_number(sit2_in[3]));
    if(car1!=car2) printf("0000");
    else{
        printf("1");
        if(sit1.first!=sit2.first){
            printf("000");
        }
        else{
            printf("1");
            if(same_side(sit1.second,sit2.second)==false){
                printf("00");
            }
            else{
                printf("1");
                if(great(sit1.second,sit2.second)){
                    printf("1");
                }
                else{
                    printf("0");
                }
            }
        }
    }
    return 0;
}
