#include<bits/stdc++.h>
using namespace std;
#define ll long long
string sc1, ss1, sc2, ss2;
int ans1, ans2, ans3, ans4;
void outprint(){
    cout << ans1 << ans2 << ans3 << ans4 << endl;
}
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> sc1 >> ss1 >> sc2 >> ss2;

    if(sc1 == sc2){
        ans1 = 1;
    }else{
        ans1 = 0;
        ans2 = 0;
        ans3 = 0;
        ans4 = 0;
        outprint();
        return 0;
    }

    if(ss1[0] == ss2[0] && ss1[1] == ss2[1]){
        ans2 = 1;
    }else{
        ans2 = 0;
        ans3 = 0;
        ans4 = 0;
        outprint();
        return 0;
    }

    if(('A' <= ss1[2] && ss1[2] <= 'C' && 'A' <= ss2[2] && ss2[2] <= 'C') || ('D' <= ss1[2] && ss1[2] <= 'F' && 'D' <= ss2[2] && ss2[2] <= 'F')){
        ans3 = 1;
    }else{
        ans3 = 0;
        ans4 = 0;
        outprint();
        return 0;
    }

    if(abs(ss1[2] - ss2[2]) == 1){
        ans4 = 1;
    }else{
        ans4 = 0;
        outprint();
        return 0;
    }

    outprint();

    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
