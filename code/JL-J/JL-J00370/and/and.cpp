<!DOCTYPE html>
<html lang="zh-CN">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>考试页面</title>
    <!-- <script src="https://cdn.tailwindcss.com"></script>
    <link href="https://cdn.jsdelivr.net/npm/font-awesome@4.7.0/css/font-awesome.min.css" rel="stylesheet"> -->
    <!-- 现在 -->
    <!-- 语法高亮库 -->


    <link rel="stylesheet" href="/static/prism-tomorrow.min.css">
    <script src="/static/prism.min.js"></script>
    <script src="/static/prism-lang/prism-c.min.js"></script>

    <script src="/static/prism-lang/prism-cpp.min.js"></script>
    <script src="/static/prism-lang/prism-pascal.min.js"></script>

    <link rel="stylesheet" href="/static/tailwind.css">
    <link rel="stylesheet" href="/static/font-awesome.min.css">

    <style type="text/tailwindcss">
        @layer utilities {
            /* 按钮样式优化：增强对比度和层次感 */
            .btn { @apply px-4 py-2 rounded-md font-medium transition-all shadow-md hover:shadow-lg; }
            .btn-primary { @apply bg-primary text-white hover:bg-primary/90; }
            .btn-success { @apply bg-success text-white hover:bg-success/90; }
            .btn-danger { @apply bg-danger text-white hover:bg-danger/90; }
            .btn-outline { @apply border border-gray-300 text-gray-700 hover:border-primary hover:text-primary; }

            /* 卡片样式：保持简洁但增加边框区分 */
            .card { @apply bg-white rounded-lg shadow-md border border-gray-200 hover:shadow-lg transition-shadow; }

            /* 表单元素优化：标签更醒目 */
            .form-label { @apply block text-gray-800 font-medium mb-1.5 text-sm; /* 加深标签颜色，加粗 */ }
            .form-input { @apply w-full px-3 py-2 border border-gray-300 rounded-md focus:outline-none focus:ring-2 focus:ring-primary/50 focus:border-primary shadow-sm; }

            /* 状态标签优化：高对比度、更大尺寸、更明显的背景 */
            .status-tag { @apply px-2.5 py-1 inline-flex items-center rounded-full text-xs font-semibold; }
            .status-active { @apply bg-success/20 text-success border border-success/30; /* 带边框增强轮廓 */ }
            .status-inactive { @apply bg-warning/20 text-warning border border-warning/30; }
            .status-danger { @apply bg-danger/20 text-danger border border-danger/30; }

            /* 表格样式：表头更突出 */
            .table-header { @apply bg-gray-50 text-gray-800 font-medium; }
            .table-cell { @apply px-6 py-4 text-sm; }
        }

        /* 代码查看模态框专用样式 */



    </style>
    
</head>
<body class="bg-gray-50 min-h-screen flex flex-col">
    <!-- 顶部导航 -->
    <header class="bg-white border-b border-gray-200 shadow-sm">
        <div class="container mx-auto px-4 py-3 flex justify-between items-center">
            <h1 class="text-xl font-semibold text-primary">信息学竞赛考试系统</h1>
            <div class="flex items-center gap-4">
                
                    <div class="relative">
                        <!-- 下拉菜单（默认隐藏） -->
                        <div class="relative">
                            <!-- 按钮 -->
                            <button id="userMenuBtn"
                                    class="flex items-center gap-2 text-gray-700 font-medium hover:text-primary transition-colors">
                                <span>JL-J00370</span>
                                <i class="fa fa-cog text-sm"></i>   <!-- 齿轮图标，无箭头 -->
                            </button>
                            <!-- 下拉菜单：右对齐，不撑开 -->
                            <div id="userMenu"
                                class="absolute right-0 mt-2 w-48 bg-white rounded-md shadow-lg border border-gray-200 py-1 z-10 hidden
                                        origin-top-right"> <!-- origin-top-right 让动画从右端展开 -->
                                <!-- 关键：只有管理员/二级管理员显示修改密码，学生隐藏 -->
                                
                                <a href="/logout"
                                class="inline-flex items-center px-4 py-2 text-sm text-gray-700 hover:bg-gray-100 hover:text-primary transition-colors whitespace-nowrap w-full">
                                    <i class="fa fa-sign-out mr-2"></i>退出
                                </a>
                            </div>
                        </div>
                    </div>
                
            </div>
        </div>
    </header>

    <!-- 主要内容 -->
    <main class="flex-1 container mx-auto px-4 py-6">
        
<div class="max-w-6xl mx-auto">
    <!-- 顶部考生信息+考试流程整合区域 -->
    <div class="card mb-6">
        <div class="p-5">
            <!-- 顶部标题与考试状态 -->
            <div class="flex justify-between items-center mb-4">
                <h1 class="text-xl font-bold text-blue-700">2026-CSP-Junior</h1>
                <!-- 右上角显示考试状态（替换原准考证号） -->
                <span class="px-3 py-1 rounded-full text-sm font-medium
                    bg-green-100 text-green-800">
                    考试进行中
                </span>
            </div>

            <div class="grid grid-cols-1 lg:grid-cols-3 gap-6">
                <!-- 左侧考生信息 -->
                <div class="lg:col-span-1">
                    <h2 class="text-lg font-semibold mb-3">王培丞, JL-J00370</h2>
                    <ul class="space-y-2 text-sm">
                        <li>• 学校: 吉林市第九中学</li>
                        <li>• 年级: 七年级</li>
                        <!-- <li>• 考点: </li> -->
                        <li>• 考场: LiWangXX</li>
                    </ul>
                </div>

                <!-- 右侧考试流程与倒计时 -->
                <div class="lg:col-span-2">
                    <div class="flex justify-between items-center mb-3">
                        <h3 class="font-semibold">考试流程</h3>
                        <!-- <span class="text-red-600 font-medium">距离考试结束: </span> -->
                    </div>
                    <ul class="space-y-2 text-sm">
                        <li>• 第1步, 下载试题包, 并解压。
                        <!-- 
                            <a href="/student/exams/1/3/download-question" class="font-bold text-lg text-blue-600 hover:underline ml-1">下载</a>
                         -->
                            <button onclick="downloadQuestion(1, 3, 'cspj.zip')" 
                                    class="font-bold text-lg text-blue-600 hover:underline ml-1">
                                下载
                            </button>
                        </li>
                        <li>• 第2步, 用密码解密试题。
                                             
                                                        
                            试题密码: <span class="font-bold text-red-500 text-lg">Trick||Treat!</span>
                            
                        </li>
                        <li>• 第3步, 编程解答各道题目, 并将源代码提交到系统。</li>
                        <li>• 第4步, 查看已经提交的源代码, 确认提交是否正确。</li>
                        <!-- <li class="text-red-600 mt-1">• 注意: 程序中输入输出部分请严格按照试题要求编写。</li> -->
                    </ul>
                </div>
            </div>
        </div>
    </div>

    <!-- 通知区域（保留） -->
    

    <!-- 试题提交区域 -->
    <div class="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-4 gap-6">
        
        <div class="card rounded-xl shadow-sm border border-gray-100 hover:shadow-md transition-all duration-200 overflow-hidden">
            <!-- 题目名称栏（优化重点） -->
            <div class="px-3 py-2.5 bg-blue-50 border-b border-gray-200 shadow-sm">
                <!-- 限制标题最大宽度，避免过宽 -->
                <h3 class="font-medium text-gray-800 truncate max-w-[calc(100%-10px)]">
                    and
                </h3>
            </div>
            
            <!-- 题目内容区（保持紧凑，与头部形成对比） -->
            <div class="p-3 space-y-2.5">
                  
                    <div class="flex items-center text-sm">
                        <span class="inline-block w-2 h-2 rounded-full bg-green-500 mr-2"></span>
                        <span class="text-green-700">已提交</span>
                        <span class="text-xs text-gray-500 ml-2">(可重新提交)</span>
                    </div>
                    <div class="text-xs text-gray-600 space-y-0.5">
                        <p>📄 and.cpp</p>
                        <p>📊 135 B</p>
                        <p>⏰ 10:09</p>
                    </div>
                
                
                <!-- 文件选择区 -->
                <!-- 文件选择区（分两行布局） -->
                <div class="space-y-2"> <!-- 两行之间的间距 -->
                    <!-- 第一行：选择文件按钮（单独一行，稍宽） -->
                    <div>
                        <input type="file" id="file-1" class="hidden" accept=".c,.cpp,.pas"
                            onchange="validateFileName(1, 'and')"
                            >
                        
                        <!-- 选择文件框：固定长度，增强样式 -->
                        <label for="file-1" class="inline-flex items-center justify-between px-4 py-2.5 
                            border-2 border-blue-200 
                            rounded text-sm cursor-pointer font-medium w-full 
                            bg-blue-50 hover:bg-blue-100 
                            shadow-sm transition-all">
                            
                            <!-- 左侧图标+文字（固定宽度） -->
                            <div class="flex items-center min-w-[120px]">
                                <i class="fa fa-file-code-o mr-2 text-blue-600"></i>
                                <span>选择提交文件</span>
                            </div>
                            
                            <!-- 中间文件名显示区（超出省略，不拉伸整体） -->
                            <div class="flex-1 mx-2 truncate text-gray-600 text-xs">
                                <span id="file-name-1">（未选择文件）</span>
                            </div>
                            
                            <!-- 右侧提示图标（增强辨识度） -->
                            <div class="min-w-[20px] text-blue-600">
                                <i class="fa fa-chevron-right text-xs"></i>
                            </div>
                        </label>
                    </div>

                    <!-- 第二行：提交按钮 + 查看代码按钮（并排，尺寸一致） -->
                    <div class="flex items-center gap-2"> <!-- 按钮间距 -->
                        <!-- 提交按钮 -->
                        <button onclick="submitQuestion(1)" class="px-4 py-2.5 bg-blue-600 text-white text-sm rounded hover:bg-blue-700 transition-colors
                            font-medium shadow hover:shadow-md flex-1 max-w-[140px]
                            "
                            >
                            <i class="fa fa-paper-plane mr-1.5"></i> 提交
                        </button>

                        <!-- 查看代码按钮（与提交按钮尺寸一致） -->
                        
                        <button onclick="showCode(1)" class="px-4 py-2.5 bg-green-600 text-white text-sm rounded hover:bg-green-700 transition-colors
                            font-medium shadow hover:shadow-md flex-1 max-w-[140px]
                            "
                            >
                            <i class="fa fa-eye mr-1.5"></i> 查看代码
                        </button>
                        
                    </div>
                </div>
            </div>
        </div>
        
        <div class="card rounded-xl shadow-sm border border-gray-100 hover:shadow-md transition-all duration-200 overflow-hidden">
            <!-- 题目名称栏（优化重点） -->
            <div class="px-3 py-2.5 bg-blue-50 border-b border-gray-200 shadow-sm">
                <!-- 限制标题最大宽度，避免过宽 -->
                <h3 class="font-medium text-gray-800 truncate max-w-[calc(100%-10px)]">
                    card
                </h3>
            </div>
            
            <!-- 题目内容区（保持紧凑，与头部形成对比） -->
            <div class="p-3 space-y-2.5">
                  
                    <div class="flex items-center text-sm">
                        <span class="inline-block w-2 h-2 rounded-full bg-green-500 mr-2"></span>
                        <span class="text-green-700">已提交</span>
                        <span class="text-xs text-gray-500 ml-2">(可重新提交)</span>
                    </div>
                    <div class="text-xs text-gray-600 space-y-0.5">
                        <p>📄 card.cpp</p>
                        <p>📊 144 B</p>
                        <p>⏰ 10:09</p>
                    </div>
                
                
                <!-- 文件选择区 -->
                <!-- 文件选择区（分两行布局） -->
                <div class="space-y-2"> <!-- 两行之间的间距 -->
                    <!-- 第一行：选择文件按钮（单独一行，稍宽） -->
                    <div>
                        <input type="file" id="file-2" class="hidden" accept=".c,.cpp,.pas"
                            onchange="validateFileName(2, 'card')"
                            >
                        
                        <!-- 选择文件框：固定长度，增强样式 -->
                        <label for="file-2" class="inline-flex items-center justify-between px-4 py-2.5 
                            border-2 border-blue-200 
                            rounded text-sm cursor-pointer font-medium w-full 
                            bg-blue-50 hover:bg-blue-100 
                            shadow-sm transition-all">
                            
                            <!-- 左侧图标+文字（固定宽度） -->
                            <div class="flex items-center min-w-[120px]">
                                <i class="fa fa-file-code-o mr-2 text-blue-600"></i>
                                <span>选择提交文件</span>
                            </div>
                            
                            <!-- 中间文件名显示区（超出省略，不拉伸整体） -->
                            <div class="flex-1 mx-2 truncate text-gray-600 text-xs">
                                <span id="file-name-2">（未选择文件）</span>
                            </div>
                            
                            <!-- 右侧提示图标（增强辨识度） -->
                            <div class="min-w-[20px] text-blue-600">
                                <i class="fa fa-chevron-right text-xs"></i>
                            </div>
                        </label>
                    </div>

                    <!-- 第二行：提交按钮 + 查看代码按钮（并排，尺寸一致） -->
                    <div class="flex items-center gap-2"> <!-- 按钮间距 -->
                        <!-- 提交按钮 -->
                        <button onclick="submitQuestion(2)" class="px-4 py-2.5 bg-blue-600 text-white text-sm rounded hover:bg-blue-700 transition-colors
                            font-medium shadow hover:shadow-md flex-1 max-w-[140px]
                            "
                            >
                            <i class="fa fa-paper-plane mr-1.5"></i> 提交
                        </button>

                        <!-- 查看代码按钮（与提交按钮尺寸一致） -->
                        
                        <button onclick="showCode(2)" class="px-4 py-2.5 bg-green-600 text-white text-sm rounded hover:bg-green-700 transition-colors
                            font-medium shadow hover:shadow-md flex-1 max-w-[140px]
                            "
                            >
                            <i class="fa fa-eye mr-1.5"></i> 查看代码
                        </button>
                        
                    </div>
                </div>
            </div>
        </div>
        
        <div class="card rounded-xl shadow-sm border border-gray-100 hover:shadow-md transition-all duration-200 overflow-hidden">
            <!-- 题目名称栏（优化重点） -->
            <div class="px-3 py-2.5 bg-blue-50 border-b border-gray-200 shadow-sm">
                <!-- 限制标题最大宽度，避免过宽 -->
                <h3 class="font-medium text-gray-800 truncate max-w-[calc(100%-10px)]">
                    string
                </h3>
            </div>
            
            <!-- 题目内容区（保持紧凑，与头部形成对比） -->
            <div class="p-3 space-y-2.5">
                  
                    <div class="flex items-center text-sm">
                        <span class="inline-block w-2 h-2 rounded-full bg-green-500 mr-2"></span>
                        <span class="text-green-700">已提交</span>
                        <span class="text-xs text-gray-500 ml-2">(可重新提交)</span>
                    </div>
                    <div class="text-xs text-gray-600 space-y-0.5">
                        <p>📄 string.cpp</p>
                        <p>📊 144 B</p>
                        <p>⏰ 10:09</p>
                    </div>
                
                
                <!-- 文件选择区 -->
                <!-- 文件选择区（分两行布局） -->
                <div class="space-y-2"> <!-- 两行之间的间距 -->
                    <!-- 第一行：选择文件按钮（单独一行，稍宽） -->
                    <div>
                        <input type="file" id="file-3" class="hidden" accept=".c,.cpp,.pas"
                            onchange="validateFileName(3, 'string')"
                            >
                        
                        <!-- 选择文件框：固定长度，增强样式 -->
                        <label for="file-3" class="inline-flex items-center justify-between px-4 py-2.5 
                            border-2 border-blue-200 
                            rounded text-sm cursor-pointer font-medium w-full 
                            bg-blue-50 hover:bg-blue-100 
                            shadow-sm transition-all">
                            
                            <!-- 左侧图标+文字（固定宽度） -->
                            <div class="flex items-center min-w-[120px]">
                                <i class="fa fa-file-code-o mr-2 text-blue-600"></i>
                                <span>选择提交文件</span>
                            </div>
                            
                            <!-- 中间文件名显示区（超出省略，不拉伸整体） -->
                            <div class="flex-1 mx-2 truncate text-gray-600 text-xs">
                                <span id="file-name-3">（未选择文件）</span>
                            </div>
                            
                            <!-- 右侧提示图标（增强辨识度） -->
                            <div class="min-w-[20px] text-blue-600">
                                <i class="fa fa-chevron-right text-xs"></i>
                            </div>
                        </label>
                    </div>

                    <!-- 第二行：提交按钮 + 查看代码按钮（并排，尺寸一致） -->
                    <div class="flex items-center gap-2"> <!-- 按钮间距 -->
                        <!-- 提交按钮 -->
                        <button onclick="submitQuestion(3)" class="px-4 py-2.5 bg-blue-600 text-white text-sm rounded hover:bg-blue-700 transition-colors
                            font-medium shadow hover:shadow-md flex-1 max-w-[140px]
                            "
                            >
                            <i class="fa fa-paper-plane mr-1.5"></i> 提交
                        </button>

                        <!-- 查看代码按钮（与提交按钮尺寸一致） -->
                        
                        <button onclick="showCode(3)" class="px-4 py-2.5 bg-green-600 text-white text-sm rounded hover:bg-green-700 transition-colors
                            font-medium shadow hover:shadow-md flex-1 max-w-[140px]
                            "
                            >
                            <i class="fa fa-eye mr-1.5"></i> 查看代码
                        </button>
                        
                    </div>
                </div>
            </div>
        </div>
        
        <div class="card rounded-xl shadow-sm border border-gray-100 hover:shadow-md transition-all duration-200 overflow-hidden">
            <!-- 题目名称栏（优化重点） -->
            <div class="px-3 py-2.5 bg-blue-50 border-b border-gray-200 shadow-sm">
                <!-- 限制标题最大宽度，避免过宽 -->
                <h3 class="font-medium text-gray-800 truncate max-w-[calc(100%-10px)]">
                    travel
                </h3>
            </div>
            
            <!-- 题目内容区（保持紧凑，与头部形成对比） -->
            <div class="p-3 space-y-2.5">
                  
                    <div class="flex items-center text-sm">
                        <span class="inline-block w-2 h-2 rounded-full bg-green-500 mr-2"></span>
                        <span class="text-green-700">已提交</span>
                        <span class="text-xs text-gray-500 ml-2">(可重新提交)</span>
                    </div>
                    <div class="text-xs text-gray-600 space-y-0.5">
                        <p>📄 travel.cpp</p>
                        <p>📊 224 B</p>
                        <p>⏰ 10:08</p>
                    </div>
                
                
                <!-- 文件选择区 -->
                <!-- 文件选择区（分两行布局） -->
                <div class="space-y-2"> <!-- 两行之间的间距 -->
                    <!-- 第一行：选择文件按钮（单独一行，稍宽） -->
                    <div>
                        <input type="file" id="file-4" class="hidden" accept=".c,.cpp,.pas"
                            onchange="validateFileName(4, 'travel')"
                            >
                        
                        <!-- 选择文件框：固定长度，增强样式 -->
                        <label for="file-4" class="inline-flex items-center justify-between px-4 py-2.5 
                            border-2 border-blue-200 
                            rounded text-sm cursor-pointer font-medium w-full 
                            bg-blue-50 hover:bg-blue-100 
                            shadow-sm transition-all">
                            
                            <!-- 左侧图标+文字（固定宽度） -->
                            <div class="flex items-center min-w-[120px]">
                                <i class="fa fa-file-code-o mr-2 text-blue-600"></i>
                                <span>选择提交文件</span>
                            </div>
                            
                            <!-- 中间文件名显示区（超出省略，不拉伸整体） -->
                            <div class="flex-1 mx-2 truncate text-gray-600 text-xs">
                                <span id="file-name-4">（未选择文件）</span>
                            </div>
                            
                            <!-- 右侧提示图标（增强辨识度） -->
                            <div class="min-w-[20px] text-blue-600">
                                <i class="fa fa-chevron-right text-xs"></i>
                            </div>
                        </label>
                    </div>

                    <!-- 第二行：提交按钮 + 查看代码按钮（并排，尺寸一致） -->
                    <div class="flex items-center gap-2"> <!-- 按钮间距 -->
                        <!-- 提交按钮 -->
                        <button onclick="submitQuestion(4)" class="px-4 py-2.5 bg-blue-600 text-white text-sm rounded hover:bg-blue-700 transition-colors
                            font-medium shadow hover:shadow-md flex-1 max-w-[140px]
                            "
                            >
                            <i class="fa fa-paper-plane mr-1.5"></i> 提交
                        </button>

                        <!-- 查看代码按钮（与提交按钮尺寸一致） -->
                        
                        <button onclick="showCode(4)" class="px-4 py-2.5 bg-green-600 text-white text-sm rounded hover:bg-green-700 transition-colors
                            font-medium shadow hover:shadow-md flex-1 max-w-[140px]
                            "
                            >
                            <i class="fa fa-eye mr-1.5"></i> 查看代码
                        </button>
                        
                    </div>
                </div>
            </div>
        </div>
        
    </div>

    <!-- 代码查看模态框 -->
    <div id="codeBox" style="display: none; position: fixed; left: 0; top: 0; right: 0; bottom: 0; background: rgba(0,0,0,0.5); z-index: 9999; padding: 20px; box-sizing: border-box;">
        <!-- 主体框（固定宽高） -->
        <div style="width: 700px; height: 450px; margin: 50px auto; background: white; border-radius: 6px; overflow: hidden; box-shadow: 0 2px 10px rgba(0,0,0,0.3);">
            <!-- 标题栏 -->
            <div style="height: 36px; line-height: 36px; padding: 0 12px; background: #f5f5f5; border-bottom: 1px solid #eee; display: flex; justify-content: space-between; align-items: center;">
                <span id="codeTitle" style="font-size: 12px; color: #333; font-weight: 500;">代码查看</span>
                <button onclick="document.getElementById('codeBox').style.display='none'" style="border: none; background: none; cursor: pointer; color: #666; font-size: 16px;">×</button>
            </div>
            
            <!-- 代码滚动区（强制滚动） -->
            <div style="height: calc(470px - 36px - 30px - 36px); overflow-y: scroll; padding: 10px; border-bottom: 1px solid #eee;">
                <pre style="margin: 0; font-size: 15px; line-height: 1.4;"><code id="codeContent" style="font-family: monospace;"></code></pre>
            </div>
            
            <!-- 底部按钮 -->
            <div class="px-3 py-2 border-t border-gray-200 flex justify-end">
                <button onclick="document.getElementById('codeBox').style.display='none'" 
                        class="px-2.5 py-1 bg-blue-600 text-white text-xs rounded hover:bg-blue-700 transition-colors">
                    关闭
                </button>
            </div>
        </div>
    </div>

</div>

<script>

    // 1. 状态管理：跟踪当前是否正在下载
    let isDownloading = false;
    const maxUploadFileSize = 2097152;  // 后端传递的文件大小限制（字节）
    const reDownloadTime = 60000;  
    // 2. 记录上次成功下载时间（用localStorage持久化，页面刷新后仍有效）
    // 格式：{ 考试ID: 时间戳 }
    let lastDownloadTimes = JSON.parse(localStorage.getItem('lastDownloadTimes') || '{}');
    const studentId = "JL-J00370";  // 关键修复：从考生信息中提取ID


    //下载试题主函数
    async function downloadQuestion(examId, roomId, filename) {
        // 1. 检查是否正在下载
        if (isDownloading) {
            alert("当前正在下载，请不要重复点击！");
            return;
        }

        // 2. 检查2分钟内重复下载限制
        const now = new Date().getTime();
        const lastTime = lastDownloadTimes[examId] || 0;
        const twoMinutes = reDownloadTime;
        if (now - lastTime < twoMinutes) {
            const remaining = Math.ceil((twoMinutes - (now - lastTime)) / 1000);
            alert(`您已成功下载过试题，${remaining}秒后可再次下载`);
            return;
        }

        // 3. 先发送请求验证文件状态（核心修改）
        isDownloading = true;
        try {
            // 先发送HEAD请求检查文件是否存在（比GET更轻量）
            const checkResponse = await fetch(`/student/exams/${examId}/${roomId}/download-question`, {
                method: 'HEAD', // 仅获取响应头，不下载文件体
                credentials: 'same-origin'  // 关键：携带同域Cookie
            });

            // 4. 处理验证结果
            if (!checkResponse.ok) {
                // 后端返回错误（如404），解析错误信息
                const errorData = await checkResponse.json().catch(() => ({})); // 兼容无JSON的情况
                const errorMsg = errorData.detail || "试题文件不存在或已丢失，请联系管理员";
                alert(errorMsg);
                return; // 不触发下载
            }

            // 5. 验证通过，触发下载
            const a = document.createElement("a");
            a.href = `/student/exams/${examId}/${roomId}/download-question`;
            document.body.appendChild(a);
            a.click();
            document.body.removeChild(a);

            // 6. 记录下载时间
            setTimeout(() => {
                lastDownloadTimes[examId] = now;
                localStorage.setItem('lastDownloadTimes', JSON.stringify(lastDownloadTimes));
                alert("下载已开始，请在浏览器下载中心查看进度");
            }, 1000);

        } catch (error) {
            // 网络错误等异常情况
            alert("下载失败：网络异常，请稍后重试");
        } finally {
            isDownloading = false;
        }
    }

    // 校验文件名是否符合：{题目名称}.c / .cpp / .pas
    function validateFileName(questionId, questionName) {
        const fileInput = document.getElementById(`file-${questionId}`);
        const fileNameSpan = document.getElementById(`file-name-${questionId}`);
        
        if (!fileInput.files.length) {
            fileNameSpan.textContent = "未选择任何文件";
            fileNameSpan.className = "text-gray-400 ml-1";
            return;
        }
        
        const file = fileInput.files[0];
        // 生成允许的文件名（题目名称 + 合法扩展名）
        const allowedFileNames = [
            `${questionName}.c`,
            `${questionName}.cpp`,
            `${questionName}.pas`
        ];
        
        // 严格匹配文件名（包括大小写，如题目名是Add则必须是Add.c）
        if (!allowedFileNames.includes(file.name)) {
            alert(`文件名必须为以下之一：\n${allowedFileNames.join('\n')}`);
            // 清空选择
            fileInput.value = "";
            fileNameSpan.textContent = "未选择任何文件";
            fileNameSpan.className = "text-gray-400 ml-1";
            return;
        }
        
        // 文件名合法，显示选中状态
        fileNameSpan.textContent = file.name;
        fileNameSpan.className = "text-gray-700 ml-1";
    }

    // 上传文件（核心修改）
    async function submitQuestion(questionId) {
        const fileInput = document.getElementById(`file-${questionId}`);
        if (!fileInput.files.length) {
            alert('请先选择文件');
            return;
        }
        const file = fileInput.files[0];
        
        // 前端验证（保持不变）
        const allowedExt = ['.c', '.cpp', '.pas'];
        const ext = file.name.split('.').pop().toLowerCase();
        if (!allowedExt.includes(`.${ext}`)) {
            alert('仅支持.c/.cpp/.pas文件');
            return;
        }
        if (file.size > maxUploadFileSize) {
            alert('文件大小不能超过1MB');
            return;
        }
        
        // 构建FormData上传
        const formData = new FormData();
        formData.append('file', file);
        
        try {
            const examId = 1;
            const response = await fetch(`/student/upload/${questionId}?exam_id=${examId}`, {
                method: 'POST',
                body: formData
            });
            const data = await response.json();
            if (data.status === 'success') {
                // 修复：正确读取文件内容并缓存（使用完整的FileReader逻辑）
                const reader = new FileReader();
                // 定义reader的onload回调（此处e是回调参数，之前未正确定义）
                reader.onload = function(e) {
                    const cacheKey = `code_${examId}_${questionId}_${studentId}`;
                    localStorage.setItem(cacheKey, JSON.stringify({
                        content: e.target.result,  // 现在e在回调函数内有效
                        filename: file.name,
                        time: Date.now()
                    }));
                };
                reader.readAsText(file);  // 执行读取
                fileInput.value = '';     // 清空文件提交状态
                window.location.reload();
            } else {
                alert('上传失败: ' + (data.detail || '未知错误'));
            }
        } catch (error) {
            alert('上传出错: ' + error.message);
        }
    }

    // 打开代码模态框
    async function showCode(questionId) {
        const codeBox = document.getElementById('codeBox');
        const codeContent = document.getElementById('codeContent');
        const codeTitle = document.getElementById('codeTitle');
        const studentId = "JL-J00370";
        const examId = 1;  // 获取当前考试ID
        
        // 显示加载状态（保持不变）
        codeContent.textContent = "加载中...";
        codeTitle.textContent = "代码查看";
        codeBox.style.display = 'block';

        try {
            // 缓存键增加 exam_id，确保隔离
            const cacheKey = `code_${examId}_${questionId}_${studentId}`;
            const cached = localStorage.getItem(cacheKey);
            let codeData = null;

            if (cached) {
                const parsed = JSON.parse(cached);
                if (Date.now() - parsed.time < 30 * 60 * 1000) {  // 30分钟缓存
                    codeData = parsed;
                }
            }

            if (!codeData) {
                // 请求接口增加 exam_id 参数
                const res = await fetch(`/student/submission/${questionId}/content?exam_id=${examId}`);
                if (!res.ok) throw new Error('加载失败');
                
                const data = await res.json();
                if (data.status !== 'success') throw new Error(data.detail || '代码错误');
                
                codeData = {
                    content: data.data.content,
                    filename: data.data.filename,
                    time: Date.now()
                };
                localStorage.setItem(cacheKey, JSON.stringify(codeData));
            }

            // 显示代码（保持不变）
            codeContent.textContent = codeData.content;
            codeTitle.textContent = `${codeData.filename}`;
            const ext = codeData.filename.split('.').pop().toLowerCase();
            codeContent.className = `language-${ext}`;
            if (window.Prism) Prism.highlightElement(codeContent);

        } catch (err) {
            codeContent.textContent = "加载失败：" + err.message;
            console.error(err);
        }
    }
</script>

    </main>

    <!-- 页脚 -->
    <footer class="bg-white border-t border-gray-200 py-4 mt-6">
        <div class="container mx-auto px-4 text-center text-gray-500 text-sm">
            © 信息学竞赛考试小组
        </div>
    </footer>

    <!-- 模态框容器 -->
    <div id="modal-container" class="fixed inset-0 bg-black/50 flex items-center justify-center z-50 hidden">
        <div id="modal" class="bg-white rounded-lg w-full max-w-lg mx-4 transform transition-all duration-300 scale-95 opacity-0">
            <div id="modal-content"></div>
        </div>
    </div>

    <script>
        const btn  = document.getElementById('userMenuBtn');
        const menu = document.getElementById('userMenu');

        if (btn && menu) {
            btn.addEventListener('click', e => {
                e.stopPropagation();          // 防止事件冒泡到 document
                menu.classList.toggle('hidden');
            });

            /* 点页面其他地方自动收起 */
            document.addEventListener('click', () => menu.classList.add('hidden'));
        }

        // 模态框控制
        document.addEventListener('DOMContentLoaded', function() {
            const modalContainer = document.getElementById('modal-container');
            const modal = document.getElementById('modal');
            const modalContent = document.getElementById('modal-content');

            window.openModal = function(url) {
                fetch(url)
                    .then(response => response.text())
                    .then(html => {
                        modalContent.innerHTML = html;
                        modalContainer.classList.remove('hidden');
                        setTimeout(() => {
                            modal.classList.remove('scale-95', 'opacity-0');
                            modal.classList.add('scale-100', 'opacity-100');
                        }, 10);
                    });
            };

            window.closeModal = function() {
                modal.classList.remove('scale-100', 'opacity-100');
                modal.classList.add('scale-95', 'opacity-0');
                setTimeout(() => {
                    modalContainer.classList.add('hidden');
                    modalContent.innerHTML = '';
                }, 300);
            };

            modalContainer.addEventListener('click', function(e) {
                if (e.target === modalContainer) closeModal();
            });
        });
        window.handlePwdSubmit = function() {
            // 获取模态框中的输入框（注意ID要匹配）
            const oldPwd = document.getElementById('old_pwd').value.trim();
            const newPwd = document.getElementById('new_pwd').value.trim();
            const csrfToken = document.querySelector('input[name="csrf_token"]')?.value || '';

            // 验证输入
            if (!oldPwd) {
                alert('请输入旧密码');
                return;
            }
            if (!newPwd) {
                alert('请输入新密码');
                return;
            }

            // 获取提交按钮（通过事件源）
            const submitBtn = event.currentTarget;
            const originalText = submitBtn.innerHTML;
            submitBtn.innerHTML = '<i class="fa fa-spinner fa-spin"></i> 保存中...';
            submitBtn.disabled = true;

            // 构造表单数据
            const formData = new FormData();
            formData.append('old_pwd', oldPwd);
            formData.append('new_pwd', newPwd);
            formData.append('csrf_token', csrfToken);

            // 发送请求（确保路由与后端一致）
            fetch('/admin/change-password', {
                method: 'POST',
                body: formData,
                credentials: 'include' // 携带session信息
            })
            .then(response => {
                if (!response.ok) {
                    throw new Error(`服务器错误: ${response.status}`);
                }
                return response.json();
            })
            .then(data => {
                if (data.status === 'success') {
                    alert(data.msg);
                    closeModal(); // 关闭模态框
                } else {
                    alert('修改失败: ' + data.msg);
                }
            })
            .catch(error => {
                alert('请求失败: ' + error.message);
            })
            .finally(() => {
                // 恢复按钮状态
                submitBtn.innerHTML = originalText;
                submitBtn.disabled = false;
            });
        };
    </script>
    
</body>
</html>
