#include <stdio.h>

int n;              // 输入的数字个数
int ring[16];       // 存放找到的环
int used[17];       // 标记数字是否用过

// 检查x是不是质数（简单版）
int isPrime(int x) {
    if (x == 2 || x == 3 || x == 5 || x == 7 || x == 11 || 
        x == 13 || x == 17 || x == 19 || x == 23 || x == 29 || x == 31)
        return 1;
    return 0;
}

// 回溯搜索（核心函数）
void dfs(int pos) {
    // 如果所有位置都填满了
    if (pos == n) {
        // 检查最后一个数和第一个数
        if (isPrime(ring[n-1] + ring[0])) {
            // 打印结果
            for (int i = 0; i < n; i++)
                printf("%d ", ring[i]);
            printf("\n");
        }
        return;
    }
    
    // 从2到n，尝试每个数字
    for (int num = 2; num <= n; num++) {
        // 如果这个数字没用，且与前一个数之和是质数
        if (!used[num] && isPrime(ring[pos-1] + num)) {
            used[num] = 1;      // 标记为已使用
            ring[pos] = num;    // 填入当前位置
            
            dfs(pos + 1);       // 继续填下一个位置
            
            used[num] = 0;      // 回溯：撤销标记，尝试别的数字
        }
    }
}

int main() {
    scanf("%d", &n);
    
    ring[0] = 1;    // 第一个位置固定为1
    used[1] = 1;    // 标记1已使用
    
    dfs(1);         // 从位置1开始填（位置0已填好1）
    
    return 0;
}