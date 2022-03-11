import jetson.inference
import jetson.utils

net = jetson.inference.detectNet(argv=['--model=jetson-inference/python/training/detection/ssd/models/Tankv2.6/ssd-mobilenet.onnx', '--labels=jetson-inference/python/training/detection/ssd/models/Tankv2.6/labels.txt', '--input-blob=input_0', '--output-cvg=scores', '--output-bbox=boxes'], threshold=0.5)
camera = jetson.utils.videoSource("csi://0")      # '/dev/video0' for V4L2
display = jetson.utils.videoOutput("display://0") # 'my_video.mp4' for file

while display.IsStreaming():
	img = camera.Capture()
	detections = net.Detect(img)
	display.Render(img)
	display.SetStatus("Tank Die Detection | Network {:.0f} FPS".format(net.GetNetworkFPS()))

num = 1
while num == 1:
	print(detections)
	delay(1)
	
